import pandas as pd
import matplotlib.pyplot as plot
import seaborn as sns


def file_check(df: pd.DataFrame):
    numeric_columns = ["sepal_length", "sepal_width", "petal_length", "petal_width"]

    for column in numeric_columns:
        converted = pd.to_numeric(df[column], errors="coerce")

        invalid = df[column].notna() & converted.isna()

        if invalid.any():
            raise ValueError("В файле содержаться данные неверного типа")

        df[column] = converted

def plot_pairplot(df: pd.DataFrame):
    columns = df.columns.tolist()[:-1]
    data = df.dropna()

    if data.empty:
        raise ValueError("Недостаточно данных для построения графика")

    graph = sns.pairplot(data, vars=columns, hue="species")

    graph.figure.suptitle("Парная диаграмма характеристик ирисов", y=1.02)

    return graph.figure


def plot_violinplot(df: pd.DataFrame):
    columns = df.columns.tolist()[:-1]
    data = df.dropna()

    if data.empty:
        raise ValueError("Недостаточно данных для построения графика")

    data_long = data.melt(
        id_vars="species",
        value_vars=columns,
        var_name="Characteristic",
        value_name="Value"
    )

    fig, ax = plot.subplots(figsize=(12, 7))

    sns.violinplot(
        data=data_long,
        x="Characteristic",
        y="Value",
        hue="species",
        ax=ax
    )

    ax.set_title("Распределение характеристик ирисов по видам")
    ax.set_xlabel("Характеристика")
    ax.set_ylabel("Значение")

    fig.tight_layout()

    return fig