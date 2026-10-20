import pandas as pd
import numpy as np
import matplotlib.pyplot as plot


def file_check(df: pd.DataFrame):
    numeric_columns = ["Matches_Played", "Kills", "Deaths", "Assists", "Damage_Dealt", "Headshots",
                       "Wins", "Top_10s", "Revives", "Distance_Traveled", "Weapons_Used", "Time_Survived"]

    for column in numeric_columns:
        converted = pd.to_numeric(df[column], errors="coerce")

        invalid = df[column].notna() & converted.isna()

        if invalid.any():
            raise ValueError("В файле содержаться данные неверного типа")

        df[column] = converted


def plot_matches_played_kills(df: pd.DataFrame):
    data = df[["Matches_Played", "Kills"]].dropna()

    if data.empty:
        raise ValueError("Недостаточно данных для построения графика")

    grouped = data.groupby("Matches_Played")["Kills"].mean()

    fig, ax = plot.subplots(figsize=(10, 6))
    ax.plot(grouped.index, grouped.values, marker='o', color='blue')

    ax.set_title("Зависимость среднего числа убийств от количества сыгранных матчей")
    ax.set_xlabel("Количество сыгранных матчей")
    ax.set_ylabel("Количество убийств")

    ax.grid(True)
    fig.tight_layout()

    return fig

def plot_rank(df: pd.DataFrame, min_count=5):
    rank_counts = df["Rank"].dropna().value_counts()

    if rank_counts.empty:
        raise ValueError("Недостаточно данных для построения графика")

    main_types = rank_counts[rank_counts >= min_count]
    other_count = rank_counts[rank_counts < min_count].sum()

    result = main_types.copy()

    if other_count > 0:
        result.loc["Other"] = other_count

    fig, ax = plot.subplots(figsize=(10, 8))

    ax.pie(result.values, labels=result.index, autopct="%1.1f%%")
    ax.set_title("Распределение количества рангов по типам")

    fig.tight_layout()

    return fig


def plot_time_survived(df: pd.DataFrame):
    data = df[["Time_Survived", "Matches_Played"]].dropna()

    if data.empty:
        raise ValueError("Недостаточно данных для построения графика")

    midtime = data["Time_Survived"] / data["Matches_Played"] / 60

    fig, ax = plot.subplots(figsize=(12, 6))

    ax.hist(midtime, bins=20)

    ax.set_title("Распределение игроков по среднему времени выживания")
    ax.set_xlabel("Среднее время выживания за матч, мин")
    ax.set_ylabel("Количество игроков")

    ax.grid(axis="y")
    fig.tight_layout()

    return fig