import requests
from pprint import pprint
from datetime import datetime
import time
import pandas


def weather_data(query):
	res=requests.get('http://api.openweathermap.org/data/2.5/weather?'+query+'&APPID=f4b16a1f05631eed8a3a6c0409ae7977&units=metric');
	return res.json();
def print_weather(result,city):
	global sunset
	sunset = (time.localtime(int(result["sys"]["sunset"])))
	global sunrise
	sunrise = (time.localtime(int(result["sys"]["sunrise"])))
	global sunset_time
	sunset_time = time.strftime("%d-%m-%Y %H:%M:%S", sunset)
	global sunrise_time
	sunrise_time = time.strftime("%d-%m-%Y %H:%M:%S", sunrise)
	global longitude_weather
	longitude_weather = result["coord"]["lon"]
	global latitude_weather
	latitude_weather = result["coord"]["lat"]
	global temperature
	temperature = result["main"]["temp"]
	global min_temp
	min_temp = result["main"]["temp_min"]
	global max_temp
	max_temp = result["main"]["temp_max"]
	global weather_all
	weather_all = result["weather"][0]["main"]

	print("{}'s temperature: {}°C ".format(city,result['main']['temp']))
	print("Feels like: {}°C ".format(result["main"]["feels_like"]))
	print("Forecast temperature: {}°C Min / {}°C Max ".format(result["main"]["temp_min"], result["main"]["temp_max"]))
	print("Wind speed: {} m/s".format(result['wind']['speed']))
	print("Description: {}".format(result['weather'][0]['description']))
	print("Weather: {}".format(result['weather'][0]['main']))
	print("Sunrise: {}".format(time.strftime("%d-%m-%Y %H:%M:%S", sunrise)))
	print("Sunset: {}".format(time.strftime("%d-%m-%Y %H:%M:%S", sunset)))



def main():
	city = input('where would you like to travel? Enter the city:')
	global city_name
	city_name = city
	print("the weather in {} is: ".format(city_name))

	print()
	try:
	  query='q='+city;
	  w_data=weather_data(query);
	  print_weather(w_data, city)
	  print()
	except:
	  print('City name not found...')

#if __name__=='__main__':
#	main()

main()
set_weather = longitude_weather, latitude_weather
#print("==========INITIAL Set=============")



#Obtain IP to locate user
import urllib.request

external_ip = urllib.request.urlopen('https://ident.me').read().decode('utf8')
#print("==========FIRST Set=============")


#get info from IP Address
def ipInfo(addr=''):
    from urllib.request import urlopen
    from json import load
    if addr == '':
        url = 'https://ipinfo.io/json'
    else:
        url = 'https://ipinfo.io/' + addr + '/json'
    res = urlopen(url)
    #response from url(if res==None then check connection)
    data = load(res)
    #will load the json response into data
    for attr in data.keys():
        #will print the data line by line
        return (attr,' '*13+'\t->\t',data[attr])

ipInfo(addr = external_ip)
#print("==========SECOND Set=============")


import ipinfo

access_token = '106f14f6de49ce'
handler = ipinfo.getHandler(access_token)
ip_address = external_ip
details = handler.getDetails(ip_address)
latitude_user = details.latitude
longitude_user = details.longitude
set_user = details.loc

#print("==========THIRD Set=============")

from math import radians, cos, sin, asin, sqrt

#def haversine(lon1, lat1, lon2, lat2):
    #convert degrees to radians
#    lon1 = radians(longitude_weather)
#    lat1 = radians(latitude_weather)
#    lon2 = radians(longitude_user)
#    lat2 = radians(latitude_user)
    #find the distance between the lon and lat
#    dlon = lon2 - lon1
#    dlat = lat2 - lat1

    #haversine calculation. 6371 is the radius of the Earth
#    a = sin(dlat/2)**2 + cos(lat1) * cos(lat2) * sin(dlon/2)**2
#    distance = 2 * asin(sqrt(a)) * 6371
#    return distance
import geopy.distance
from geopy.distance import geodesic

print("The distance between you and the {} is {} km".format(city_name, int(geodesic(set_weather, set_user).km)))