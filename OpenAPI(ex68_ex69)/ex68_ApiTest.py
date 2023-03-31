import requests

res = requests.get("http://api.openweathermap.org/data/2.5/weather?q=seoul&APPID=638c194eada65884c5449fa30f9c2fd2&lang=krhttp://api.openweathermap.org/data/2.5/weather?q=seoul&APPID=638c194eada65884c5449fa30f9c2fd2&lang=kr")

print(res.status_code)
print(res.text)

weather = res.json() 
print(weather['main'])