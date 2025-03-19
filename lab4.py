import cv2
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

# Load the custom shapes image
image_path = r"C:\Users\sneha\Downloads\shapes.png"  # Ensure this path is correct
image = cv2.imread(image_path)

# Check if image is loaded correctly
if image is None:
    print("Error: OpenCV could not load the image. Check the file path!")
    exit()

# Resize if needed (Optional)
image = cv2.resize(image, (400, 400))

# Apply K-means clustering
def apply_kmeans(image, k=5):
    """Applies K-means clustering to segment the image into k colors."""
    pixels = image.reshape((-1, 3))  # Convert to 2D array of pixels
    pixels = np.float32(pixels)  # Convert to float for K-Means

    kmeans = KMeans(n_clusters=k, n_init=10, random_state=42)
    kmeans.fit(pixels)

    # Replace each pixel with its cluster center
    segmented_pixels = kmeans.cluster_centers_[kmeans.labels_]

    # Convert back to uint8 format
    segmented_image = segmented_pixels.reshape(image.shape).astype(np.uint8)

    return segmented_image, kmeans

segmented_image, kmeans = apply_kmeans(image)

# Display both images side by side
plt.figure(figsize=(10, 5))  # Create a wider figure for side-by-side display

# Show the original image
plt.subplot(1, 2, 1)  # (rows, columns, index)
plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
plt.axis("off")
plt.title("Original Image")

# Show the segmented image
plt.subplot(1, 2, 2)  # (rows, columns, index)
plt.imshow(cv2.cvtColor(segmented_image, cv2.COLOR_BGR2RGB))
plt.axis("off")
plt.title("Segmented Image using K-means")

plt.show()  # Display both images at the same time
