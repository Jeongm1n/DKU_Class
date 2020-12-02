"""
Problem #3
"""

class Country:
    def __init__(self, name, capital_city, population, area):
        self.name = name
        self.capital_city = capital_city
        self.population = population
        self.area = area
        self.density = round(self.area / self.population, 3)

name = ["U.S", "China", "Brazil", "Canada"]
capital_city = ["Washington", "Beijing", "Brasilia", "Ottawa"]
population = [309975000, 1339190000, 193364000, 34207000]
area = [9629091, 9596960, 8511965, 9976140]

country = []
for i in range(4):
    country.append(Country(name[i], capital_city[i], population[i], area[i]))
print(" Name          Capital         Population          Area")
for i in range(len(country)):
    print("-------------------------------------------------------")
    print(country[i].name, end='        ')
    print(country[i].capital_city, end='         ')
    print(country[i].population, end='          ')
    print(country[i].area)
def max_Area(country):
    area = []
    for i in range(len(country)):
        area.append(country[i].area)
    Largest_area = max(area)
    Largest_area_idx = area.index(Largest_area)
    print("\n\nThe country with the largest area", end=' : ')
    print(country[Largest_area_idx].name, end=', ')
    print(country[Largest_area_idx].area)
    
def max_Population(country):
    population = []
    for i in range(len(country)):
        population.append(country[i].population)
    Largest_pop = max(population)
    Largest_pop_idx = population.index(Largest_pop)
    print("\nThe country with the largest population", end=' : ')
    print(country[Largest_pop_idx].name, end=', ')
    print(country[Largest_pop_idx].population)
    
    
def max_Density(country):
    density = []
    for i in range(len(country)):
        density.append(country[i].density)
    Largest_density = max(density)
    Largest_density_idx = density.index(Largest_density)
    print("\nThe country with the largest density", end=' : ')
    print(country[Largest_density_idx].name, end=', ')
    print(country[Largest_density_idx].density)


def Capitalcity(country):
    print('\n-----Country capital city information-----')
    for i in range(len(country)):
        print(country[i].name, end=' : ')
        print(country[i].capital_city)
        
max_Area(country)
max_Population(country)
max_Density(country)
Capitalcity(country)


