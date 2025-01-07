import requests
from bs4 import BeautifulSoup

url = "https://pokemondb.net/ability"
response = requests.get(url)

soup = BeautifulSoup(response.text, "html.parser")
abilities = soup.find_all("a", class_="ent-name")
ability_descriptions = soup.find_all("td", class_="cell-med-text")

with open("../data/ability.txt", "w") as file:
    for ability, description in zip(abilities, ability_descriptions):
        ability_name = ability.get_text()
        ability_des = description.get_text().replace("Poké", "Poke")
        file.write(f"{ability_name}: {ability_des}\n")