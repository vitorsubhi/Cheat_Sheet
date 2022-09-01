import matplotlib.pyplot as plt
import re

def generate(name, json, currency, compare):
    exib = []
    ay = []
    for dia in sorted(json):
        exib.append(re.sub("2019-", "", dia))
        day = json[dia]
        ay.append(day[compare])
    
    plt.title(currency + ' - ' + compare)
    plt.plot(exib,ay)
    plt.xlabel('Data')
    plt.ylabel('Valor')
    plt.savefig(name+'.png',dpi = 300, bbox_inches='tight')
