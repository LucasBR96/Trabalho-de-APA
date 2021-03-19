import matplotlib.pyplot as pplt
import numpy
import csv
import pandas
import random

# '''
#     Esse arquivo contém o script responsável em gerar os graficos que serão utilizados na apresentação de Powerpoin
#     A SOLUÇÃO NÃO SE ENCONTRA AQUI 
# '''

std_itens = 50
std_peso = 5000

def media_movel( arr , k = 5 ):

    seq = [  ]
    mu = arr[ :k ].mean()
    for i in range( len( arr ) - k ):
        seq.append( mu )
        s = ( arr[ i + k ] - arr[ i ] )/k
        mu = mu + s
    return numpy.array( mu )

def gerar_tab( ):

    global groomed_tab

    tab = pandas.read_csv( "resultados.csv" )
    tab = tab[ [ "i" , "N" , "M" , "t" ] ]
    groomed_tab = tab.rename(
        columns = {
        "M":"Limite de Peso",
        "N":"Numero de itens",
        "i":"Solução",
        "t":"Tempo( Ms )",
        }
    )

    groomed_tab["Tempo( Ms )"] = tab["t"]*1000

    groomed_tab.loc[ tab[ "i" ] == 0 , "Solução"] = "Ingênua"
    groomed_tab.loc[ tab[ "i" ] == 1 , "Solução"] = "Otimizada 1"
    groomed_tab.loc[ tab[ "i" ] == 2 , "Solução"] = "Otimizada 2"

    return groomed_tab

def isolar_itens( solucao , coluna ):

    if coluna == "Numero de itens":
        outra = "Limite de Peso"
        v = std_peso
    else:
        outra = "Numero de itens"
        v = std_itens
    
    s = ( groomed_tab["Solução"] == solucao and groomed_tab[outra] == v )
    tab = groomed_tab[ [ coluna, "Tempo( MS )" ] ]
    return tab[ s ].sort_values( by = coluna )

def gerar_grafico( coluna , tab , ax ):
    ax.plot( coluna, "Tempo( MS )", tab, color = 'red', linewidth = 4 )

            

def main( ):

    gerar_tab( )
    solucoes = [ "Ingênua" , "Otimizada 1" , "Otimizada 2" ]
    Variavel = [ "Numero de itens" , "Limite de Peso" ]

    for solucao in solucoes:
        s = "Performance para solucao {}".format( solucao )
        fig , axes = pplt.subplots( 1 , 2 , sharey = "row", label = s )
        for ax , var in zip( axes , Variavel ):
            tab = isolar_itens( solucao , var )
            gerar_grafico( var , tab, ax )
        pplt.show()

if __name__ == "__main__":
    main()
