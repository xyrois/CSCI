#Name:  Brinta Kundu
#Email: brinta.kundu37@myhunter.cuny.edu
#Date:  November 13,2023
#This program creates a map with markers for all traffic collisions
  
import folium
import pandas as pd

inF = input('Enter input filename:')
outF = input('Enter output filename:')

collisions = pd.read_csv(inF)
collisions["LATITUDE"] = collisions["LATITUDE"].fillna(0)
collisions["LONGITUDE"] = collisions["LONGITUDE"].fillna(0)

mapCrash = folium.Map(location = [40.768731, -73.964915])

for index, row in collisions.iterrows():
	if row['LATITUDE'] != 0 and row['LONGITUDE'] != 0:
            newMarker = folium.Marker([row['LATITUDE'],row['LONGITUDE']])
            mapCrash.add_child(newMarker)

mapCrash.save(outfile=outF)
