import requests
import matplotlib.pyplot as plt

def fibonacci(_from, _to):
    if (_from < _to):
        _max = _to
        _min = _from
    else:
        _max = _from
        _min = _to
    n1 = (((_max - _min)*0.236) + _min)
    n2 = (((_max - _min)*0.382) + _min)
    n3 = (((_max - _min)*0.5) + _min)
    n4 = (((_max - _min)*0.618) + _min)
    n5 = (((_max - _min)*1.618) + _min)
    n6 = (((_max - _min)*2.618) + _min)
    return [_min, n1, n2, n3, n4, _max, n5, n6]

def fibonacci_graph(_from, _to, x):
    fib = fibonacci(_from, _to)
    exib = []
    n = []
    for i in  range(x):
        exib.append (i)

    for element in fib:
        add = []
        for i in range(x):
            add.append(element)
        n.append(add)

    for i in range (7):
        plt.plot (exib, n[i])
    plt.savefig('Images/'+'fib.png', dpi=300, bbox_inches='tight')

def info(json, currency, compare):
    maximo = 0
    media = 0
    for dia in sorted(json):
        day = json[dia]
        if (maximo == 0 or day[compare] < minimo):
            minimo = day[compare]
        if (day[compare] > maximo):
            maximo = day[compare]
        media = media + day[compare]
    media = media / len(json)
    return [minimo, media, maximo]
