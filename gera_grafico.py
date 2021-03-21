import matplotlib.pyplot as pplt
import numpy
import csv
import pandas
import random
from math import floor , ceil

# '''
#     Esse arquivo contém o script responsável em gerar os graficos que serão utilizados na apresentação de Powerpoin
#     A SOLUÇÃO NÃO SE ENCONTRA AQUI 
# '''

std_itens = 50
std_peso = 5000

def media_movel( arr , k = 5 ):

    seq = [  ]
    mu = arr[ :k ].mean()
    top = ceil( k/2 )
    bottom = floor( k/2 )
    for i in range( len( arr )):
        seq.append( mu )
        j_top  = min( i + top , len(arr) - 1 )
        j_floor = max( i - bottom , 0 )
        s = ( arr[ j_top ] - arr[ j_floor ] )/k
        mu = mu + s

    return numpy.array( seq )

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

    groomed_tab.loc[ tab[ "i" ] == 0 , "Solução"] = "ingênua"
    groomed_tab.loc[ tab[ "i" ] == 1 , "Solução"] = "otimizada 1"
    groomed_tab.loc[ tab[ "i" ] == 2 , "Solução"] = "otimizada 2"

    return groomed_tab

def isolar_itens( solucao , coluna ):

    if coluna == "Numero de itens":
        outra = "Limite de Peso"
        v = std_peso
    else:
        outra = "Numero de itens"
        v = std_itens
    
    # s = ( groomed_tab["Solução"] == solucao & groomed_tab[outra] == v )


    s1 = groomed_tab["Solução"] == solucao
    s2 = groomed_tab[outra] == v
    s = s1&s2

    tab = groomed_tab[[coluna,'Tempo( Ms )']]
    tab = tab[ s ].sort_values( by = coluna )

    return tab

def gerar_grafico( coluna , tab , ax ):
    # var = 'Tempo( Ms )'
    # ax.plot( coluna, var , tab, color = 'red', linewidth = 4 )

    x_s = tab[ coluna ].to_numpy()
    y_s = tab[ "Tempo( Ms )"].to_numpy()
    y_s = media_movel(y_s, k = 25 )

    col = 'red'
    line_width = 2 

    ax.plot( x_s , y_s, color = col , linewidth = line_width )
    ax.set_title( coluna )


            

def main( ):

    gerar_tab( )
    # solucoes = [ "Ingênua" , "Otimizada 1" , "Otimizada 2" ]
    solucoes = [ "otimizada 1" , "otimizada 2"  ]
    Variavel = [ "Numero de itens" , "Limite de Peso" ]

    for solucao in solucoes:
        s = "Performance para solução {}".format( solucao )
        fig , axes = pplt.subplots( 1 , 2 , sharey = "row")
        # fig , axes = pplt.subplots( 1 , 2 )
        fig.suptitle( s )
        for ax , var in zip( axes , Variavel ):
            tab = isolar_itens( solucao , var )
            gerar_grafico( var , tab, ax )
        pplt.show()


if __name__ == "__main__":
    main()
