import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import cv2
import numpy as np

# Load the image from file
image_path = r"C:\Users\user\Downloads\shapes (1).png"
img = cv2.imread(image_path)

# Convert BGR to RGB (since OpenCV loads images in BGR format)
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

img.shape

x = img.reshape(-1, 3)

x.shape

# Apply K-Means clustering
K = 3  # Define K before using it
k_means = KMeans(n_clusters=K, n_init=10)  # Keeping n_init to suppress warnings
k_means.fit(x)

# Reshape labels to match image dimensions
labels = k_means.labels_.reshape(img.shape[:2])  # Define labels before using

segmented_image = k_means.cluster_centers_[k_means.labels_]
segmented_image = segmented_image.reshape(img.shape)

plt.imshow(img)
plt.title("Original Image")
plt.axis("off")
plt.show()

# Show the segmented image
plt.imshow(segmented_image / 255)  # Normalize for display
plt.title("Segmented Image (K-Means)")
plt.axis("off")
plt.show()

# Extract and display each shape separately
for i in range(K):
    mask = (labels == i).astype(np.uint8)  # Convert to binary mask
    
    # Find connected components (shapes)
    num_labels, labeled_mask = cv2.connectedComponents(mask)
    
    for j in range(1, num_labels):  # Skip background (label 0)
        shape_mask = (labeled_mask == j).astype(np.uint8) * 255  # Isolate one shape
        
        # Extract the shape from the original image
        extracted_shape = np.zeros_like(img)
        extracted_shape[shape_mask == 255] = img[shape_mask == 255]

        # Display each extracted shape
        plt.imshow(extracted_shape)
        plt.title(f"Shape {j} from Cluster {i+1}")
        plt.axis("off")
        plt.show()
