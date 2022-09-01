import requests

def latestData(currency):
    URL = "https://api.exchangeratesapi.io/latest?base="+ currency
    response = requests.get(URL)
    return response.json()

def dateData(currency, date):
    URL = "https://api.exchangeratesapi.io/"+ date +"?base="+ currency
    response = requests.get(URL)
    return response.json()

def periodData(currency, start_date, end_date):
    URL = "https://api.exchangeratesapi.io/history?start_at="+ start_date +"&end_at="+ end_date +"&base="+ currency
    response = requests.get(URL)
    return response.json()
