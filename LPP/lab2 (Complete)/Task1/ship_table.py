import pandas as pd
import numpy as np
import matplotlib.pyplot as plot


def file_check(df: pd.DataFrame):
    numeric_columns = ["length", "dwt", "built_year"]

    for column in numeric_columns:
        converted = pd.to_numeric(df[column], errors="coerce")

        invalid = df[column].notna() & converted.isna()

        if invalid.any():
            raise ValueError("В файле содержаться данные неверного типа")

        df[column] = converted

    years = df["built_year"].dropna()

    if (years % 1 != 0).any():
        raise ValueError("В файле содержаться данные неверного типа")


def plot_average_dwt_by_length(df: pd.DataFrame):
    data = df[["length", "dwt"]]

    stats = data.describe()
    print(stats)
    total_rows = len(data)
    
    count_length = stats.loc['count', 'length']
    count_dwt = stats.loc['count', 'dwt']
    
    if count_length < total_rows or count_dwt < total_rows:
        missing_length = int(total_rows - count_length)
        missing_dwt = int(total_rows - count_dwt)

        print(f"Кол-во пропущенеых значении длины: {missing_length}, двт: {missing_dwt}. ")

    data = data.dropna()

    if data.empty:
        raise ValueError("Недостаточно данных для построения графика")

    grouped = data.groupby("length")["dwt"].mean()

    fig, ax = plot.subplots(figsize=(10, 6))
    ax.plot(grouped.index, grouped.values, marker='o', color='blue')

    ax.set_title("Зависимость средней максимальной загрузки от длины корабля")
    ax.set_xlabel("Длина корабля")
    ax.set_ylabel("Средняя максимальная загрузка (DWT)")

    ax.grid(True)
    fig.tight_layout()

    return fig


def plot_ship_types(df: pd.DataFrame, min_count=5):
    ship_counts = df["ship_name"].dropna().value_counts()

    if ship_counts.empty:
        raise ValueError("Недостаточно данных для построения графика")

    main_types = ship_counts[ship_counts >= min_count]
    other_count = ship_counts[ship_counts < min_count].sum()

    result = main_types.copy()

    if other_count > 0:
        result.loc["Other"] = other_count

    fig, ax = plot.subplots(figsize=(10, 8))

    ax.pie(result.values, labels=result.index, autopct="%1.1f%%")
    ax.set_title("Распределение количества кораблей по типам")

    fig.tight_layout()

    return fig


def plot_ships_by_year(df: pd.DataFrame):
    years = df["built_year"].dropna()

    if years.empty:
        raise ValueError("Недостаточно данных для построения графика")

    min_year = int(years.min())
    max_year = int(years.max())

    bins = np.arange(min_year, max_year + 2) - 0.5

    fig, ax = plot.subplots(figsize=(12, 6))

    ax.hist(years, bins=bins)

    ax.set_title("Распределение количества кораблей по годам постройки")
    ax.set_xlabel("Год постройки")
    ax.set_ylabel("Количество кораблей")

    ax.grid(axis="y")
    fig.tight_layout()

    return fig


def plot_year_dwt_histogram(df: pd.DataFrame):
    data = df[["built_year", "dwt"]].dropna()

    if data.empty:
        raise ValueError("Недостаточно данных для построения графика")

    years = data["built_year"].values
    dwt = data["dwt"].values

    dwt_bins = np.linspace(dwt.min(), dwt.max(), 21)

    fig, ax = plot.subplots(figsize=(12, 7))

    histogram = ax.hist2d(years, dwt, bins=[20, dwt_bins])

    fig.colorbar(histogram[3], ax=ax, label="Количество кораблей")

    ax.set_title("Распределение кораблей по году постройки и максимальному весу груза")
    ax.set_xlabel("Год постройки")
    ax.set_ylabel("Максимальный вес груза (DWT)")

    fig.tight_layout()

    return fig