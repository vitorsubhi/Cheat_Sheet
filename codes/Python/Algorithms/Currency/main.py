import datetime as date
import currency
import tools
import graphics

#week = ["Segunda", "Terca", "Quarta", "Quinta", "Sexta"]
#month = ["01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31" ]
#year = ["Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"]

date_full = date.datetime.now().strftime("%Y-%m-%d")
date_day = date.datetime.now().strftime("%d")
date_month = date.datetime.now().strftime("%m")
date_year = date.datetime.now().strftime("%Y")

filename = "7"
compare_from = "BRL"
compare_to = "EUR"
start_date = "2019-01-01"
#end_date = date_full
end_date = "2019-10-11"

responseJSON = currency.periodData(compare_from, start_date, date_full)
rates = responseJSON['rates']

#generate_graph("1", rates, "BRL", "CAD")
graphics.generate('Images/' + filename, rates, compare_from, compare_to)

dados = tools.info(rates, compare_from, compare_to)


print ("Minimo: ", dados[0], '\nMedia: ', dados[1], '\nMaximo: ', dados[2])

tools.fibonacci_graph(dados[0], dados[2], 200)
