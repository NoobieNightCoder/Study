import matplotlib.pyplot as plt
import numpy as np
import sklearn.cluster as sl
import os

MAX_FILE_SIZE = 1024*1024*  5 # МБ

def read_file(filename: str) -> np.ndarray:
    try:
        if os.path.exists(filename) and os.path.getsize(filename) > MAX_FILE_SIZE:
            print("Ошибка: Файл слишком большой.")
            result = np.empty((0, 2), dtype=int)
        else:
            result = np.loadtxt(filename, dtype=int, usecols=(0, 1))
    except FileNotFoundError:
        print("Ошибка: Файл не найден.")
        result = np.empty((0, 2), dtype=int)
    except ValueError:
        print("Ошибка: Файл поврежден или содержит неверный формат данных.")
        result = np.empty((0, 2), dtype=int)

    return result


def kmeans_clustering(array: np.array, clusters = 5):
    k_means = sl.KMeans(n_clusters=clusters, random_state=0, n_init="auto").fit(array)
    labels = k_means.labels_
    centroids = k_means.cluster_centers_

    plt.figure(figsize=(8, 6))

    plt.scatter(array[:, 0], array[:, 1], c=labels, cmap='tab20', s=30, label='Кластеры')

    plt.scatter(centroids[:, 0], centroids[:, 1], c='red', s=30, label='Центроиды')

    plt.title(f'Визуализация кластеризации KMeans (k={clusters})', fontsize=11)
    plt.xlabel('Координата X')
    plt.ylabel('Координата Y')
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.5)
    plt.show()

def agl_clustering(array: np.array, clusters = 5):
    agl_clusters = sl.AgglomerativeClustering(n_clusters=clusters).fit(array)
    labels = agl_clusters.labels_

    plt.figure(figsize=(8, 6))

    plt.scatter(array[:, 0], array[:, 1], c=labels, cmap='tab20', s=30, label='Кластеры')

    plt.title(f'Визуализация кластеризации AgglomerativeClustering (k={clusters})', fontsize=11)
    plt.xlabel('Координата X')
    plt.ylabel('Координата Y')
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.5)

    plt.show()

def dbscan_clustering(array: np.arange, eps = 34000, min_samples = 20):
    dbscan = sl.DBSCAN(eps=eps, min_samples=min_samples).fit(array)
    labels = dbscan.labels_

    n_clusters = len(set(labels)) - (1 if -1 in labels else 0)

    plt.figure(figsize=(8, 6))

    cluster_mask = labels != -1
    plt.scatter(array[cluster_mask, 0], array[cluster_mask, 1], c=labels[cluster_mask], cmap='tab20', s=30, label='Кластеры')

    noise_mask = labels == -1
    plt.scatter(array[noise_mask, 0], array[noise_mask, 1], c='black', s=20, label='Шум')

    plt.title(f'Визуализация кластеризации DBScan (k={n_clusters})', fontsize=11)
    plt.xlabel('Координата X')
    plt.ylabel('Координата Y')
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.5)

    plt.show()