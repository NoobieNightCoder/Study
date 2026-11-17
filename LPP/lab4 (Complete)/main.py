import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import os
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
from sklearn.model_selection import train_test_split

MAX_FILE_SIZE = 1024*1024*  5 # МБ
FEATURE = "death_rate"
TARGET = "npg"

def read_file(filename: str) -> np.ndarray:
    try:
        if os.path.exists(filename) and os.path.getsize(filename) > MAX_FILE_SIZE:
            print("Ошибка: Файл слишком большой.")
            result = np.empty((0, 2))
        else:
            data = pd.read_csv(filename, usecols=[FEATURE, TARGET]).dropna()
            result = data[[FEATURE, TARGET]].to_numpy()
    except FileNotFoundError:
        print("Ошибка: Файл не найден.")
        result = np.empty((0, 2))
    except ValueError:
        print("Ошибка: Файл поврежден или содержит неверный формат данных.")
        result = np.empty((0, 2))

    return result


def linear_regression(array: np.ndarray, test_size = 0.2) -> LinearRegression:
    x = array[:, 0].reshape(-1, 1)
    y = array[:, 1]
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=test_size, random_state=0)

    model = LinearRegression().fit(x_train, y_train)
    r2 = r2_score(y_test, model.predict(x_test))

    print(f"Уравнение регрессии: y = {model.coef_[0]:.3f} * x + {model.intercept_:.3f}")
    print(f"R^2 на тестовой выборке: {r2:.3f}")

    line_x = np.linspace(x.min(), x.max(), 100).reshape(-1, 1)

    plt.figure(figsize=(8, 6))

    plt.scatter(x_train, y_train, c='tab:blue', s=15, alpha=0.4, label='Обучающая выборка')
    plt.scatter(x_test, y_test, c='green', s=15, alpha=0.7, label='Тестовая выборка')
    plt.plot(line_x, model.predict(line_x), c='red', linewidth=2, label='Линия регрессии')

    plt.title(f'Линейная регрессия (R^2={r2:.3f})', fontsize=11)
    plt.xlabel('Смертность, на 1000 чел.')
    plt.ylabel('Естественный прирост, на 1000 чел.')
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.5)
    plt.show()

    return model


def predict_values(model: LinearRegression, array: np.ndarray):
    points = []

    print("Введите значение смертности на 1000 чел. (для выхода введите exit)")

    exitFlag = False
    while not exitFlag:
        text = input("> ").strip().replace(",", ".")
        if text.lower() == "exit":
            exitFlag = True
        else:
            try:
                value = float(text)
            except ValueError:
                print("Ошибка: Нужно ввести число.")
                continue
            prediction = model.predict([[value]])[0]
            points.append((value, prediction))
            print(f"Предсказанный естественный прирост: {prediction:.2f}")

    if points:
        line_x = np.linspace(array[:, 0].min(), array[:, 0].max(), 100).reshape(-1, 1)
        points = np.array(points)

        plt.figure(figsize=(8, 6))

        plt.scatter(array[:, 0], array[:, 1], c='tab:blue', s=15, alpha=0.3, label='Данные')
        plt.plot(line_x, model.predict(line_x), c='red', linewidth=2, label='Линия регрессии')
        plt.scatter(points[:, 0], points[:, 1], c='black', marker='*', s=150, zorder=5, label='Предсказания')

        plt.title('Предсказания линейной регрессии', fontsize=11)
        plt.xlabel('Смертность, на 1000 чел.')
        plt.ylabel('Естественный прирост, на 1000 чел.')
        plt.legend()
        plt.grid(True, linestyle='--', alpha=0.5)
        plt.show()