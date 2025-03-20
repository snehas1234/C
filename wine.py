import pandas as pd
import numpy as np
from scipy.stats import skew, entropy
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score

# Load the dataset
df = pd.read_csv("winequality-red.csv", sep=';')

# Function to compute statistics
def compute_stats(data):
    stats = {}
    for col in data.columns:
        if col != 'quality':  # Skip the target variable
            stats[col] = {
                'mean': np.mean(data[col]),
                'variance': np.var(data[col]),
                'skewness': skew(data[col]),
                'entropy': entropy(np.histogram(data[col], bins=10)[0])  # Discretizing for entropy
            }
    return stats

# Compute statistics
stats = compute_stats(df)

# Convert to DataFrame for analysis
stats_df = pd.DataFrame(stats).T  # Transpose for readability

# 1. Find the most important predictor using correlation with quality
correlations = df.corr()['quality'].drop('quality').abs()  # Absolute correlation with quality
most_important_stat = correlations.idxmax()  # Feature with highest correlation

# 2. Check if high entropy features make classification harder
high_entropy_features = stats_df.sort_values(by='entropy', ascending=False).index[:3]  # Top 3
print(f"High entropy features: {list(high_entropy_features)}")

# 3. Train a simple model before and after dropping high-variance features
high_variance_features = stats_df.sort_values(by='variance', ascending=False).index[:3]  # Top 3

# Model without dropping features
X = df.drop(columns=['quality'])
y = df['quality']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
model = LinearRegression().fit(X_train, y_train)
full_model_score = r2_score(y_test, model.predict(X_test))

# Model after dropping high-variance features
X_reduced = X.drop(columns=high_variance_features)
X_train_r, X_test_r, y_train_r, y_test_r = train_test_split(X_reduced, y, test_size=0.2, random_state=42)
model_reduced = LinearRegression().fit(X_train_r, y_train_r)
reduced_model_score = r2_score(y_test_r, model_reduced.predict(X_test_r))

# Print Results
print("\nFeature Statistics:")
print(stats_df)

print(f"\nMost important predictor of wine quality: {most_important_stat}")

print(f"\nR² Score with all features: {full_model_score:.4f}")
print(f"R² Score after dropping high-variance features: {reduced_model_score:.4f}")

# Interpretation
if reduced_model_score < full_model_score:
    print("\nDropping high-variance features reduced model performance.")
else:
    print("\nDropping high-variance features did not significantly affect performance.")

