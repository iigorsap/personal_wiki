import pandas as pd
from bs4 import BeautifulSoup
import requests
import sqlite3

url = 'https://en.everybodywiki.com/100_Most_Highly-Ranked_Films'

db_name = './out/Movies.db'
table_name = 'Top_50'
csv_path = './out/top_50_films.csv'
columns=["Average Rank","Film","Year"]
df = pd.DataFrame(columns=columns)
count = 0

html_page = requests.get(url).text
data = BeautifulSoup(html_page, 'html.parser')

tables = data.find_all('tbody')
rows = tables[0].find_all('tr')

# columns = rows[1].find_all('td')
# print(columns[0].text)

for count, row in enumerate(rows):
    if count <= 50:
        if count != 0:
            column = row.find_all('td')
            average_rank = int(column[0].text)
            film = column[1].text
            year = int(column[2].text)

            dict = {
                "Average Rank" : [average_rank],
                "Film" : [film],
                "Year" : [year]
            }

            df_aux = pd.DataFrame(dict)
            df = pd.concat([df, df_aux], ignore_index=True)
    else:
        break;

print(df)

# Load to csv
df.to_csv(csv_path)

conn = sqlite3.connect(db_name)
df.to_sql(table_name, conn, if_exists='replace', index=False)
conn.close()

