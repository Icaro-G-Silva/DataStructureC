import sys
from numpy import NaN
import pandas as pd
from matplotlib import pyplot as plt
sys.path.append('./algorithms')

FIGSIZE = (14,8.5)
ADJUST_TOP = 0.92
ADJUST_RIGHT = 0.95
ROTATION = 45

def organizeTargetColumn(dataframe):
  targetColumn = pd.Series(dataframe['Target'])
  targetColumn = targetColumn.str.removeprefix('../unsorted/')
  targetColumn = targetColumn.str.removeprefix('../sorted/')
  targetColumn = targetColumn.str.removesuffix('.txt')
  return targetColumn

def organizeIteractionsColumn(dataframe):
  iteractionColumn = pd.Series(dataframe['Iteractions'])
  for index, iteraction in iteractionColumn.items():
    if iteraction < 0: iteractionColumn[index] = NaN
  return iteractionColumn

def plotMainGraphics(targets_df):
  for key in targets_df.keys():
    if key is NaN: continue
    timeRelation = targets_df[key].copy()
    iteractionRelation = targets_df[key].copy()
    timeRelation.pop('Iteractions')
    iteractionRelation.pop('Time (μs)')

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=FIGSIZE)

    timePlot = timeRelation.plot.bar(x='Algorithm', title=key, ax=ax1)
    timePlot.set_xticklabels(timeRelation['Algorithm'], rotation=ROTATION)

    iteractionPlot = iteractionRelation.plot.bar(x='Algorithm', title=key, ax=ax2)
    iteractionPlot.set_xticklabels(timeRelation['Algorithm'], rotation=ROTATION)

    plt.subplots_adjust(top=ADJUST_TOP, right=ADJUST_RIGHT)
    plt.show()
    fig.savefig(f'graphics/Relation_of_{key}.png', dpi=fig.dpi)

def plotMeanGraphics(algorithms_df):
  fig, (ax1, ax2) = plt.subplots(1, 2, figsize=FIGSIZE)
  algorithms_df['Time (μs)'].plot.barh(x='Time (μs)', y='Algorithm', title='Average Time', ax=ax1)
  algorithms_df['Iteractions'].plot.barh(x='Iteractions', y='Algorithm', title='Average Iteractions', ax=ax2)
  plt.subplots_adjust(top=ADJUST_TOP, right=ADJUST_RIGHT)
  plt.show()
  fig.savefig('graphics/Averages.png', dpi=fig.dpi)

if __name__ == '__main__':
  df = pd.read_csv('stats.csv', sep=';')

  df = df[df['Algorithm'] != 'QUICK NÃO RODOU'] #specific stats.csv field
  df = df.rename(columns={'Time': 'Time (μs)'})

  df['Target'] = organizeTargetColumn(df)
  df['Iteractions'] = organizeIteractionsColumn(df)

  algorithms_df = df.groupby(['Algorithm']).mean()

  uniqueTargets = df['Target'].unique()
  targets_df = {}
  for target in uniqueTargets:
    targets_df[target] = df[df['Target'] == target]
    targets_df[target].pop('Target')

  plotMainGraphics(targets_df)
  plotMeanGraphics(algorithms_df)
