import networkx as nx
import plotly.graph_objects as go
import random

def carregar_grafo(arquivo):
    grafo = nx.read_edgelist(arquivo, create_using=nx.Graph(), nodetype=str)
    return grafo

def propriedades_grafo(grafo):
    num_nos = grafo.number_of_nodes()
    num_arestas = grafo.number_of_edges()
    print(f"Número de Nós: {num_nos}")
    print(f"Número de Arestas: {num_arestas}")

def visualizar_grafo(grafo):
    pos = nx.spring_layout(grafo)
    
    arestas_x = []
    arestas_y = []
    for edge in grafo.edges():
        x0, y0 = pos[edge[0]]
        x1, y1 = pos[edge[1]]
        arestas_x += [x0, x1, None]
        arestas_y += [y0, y1, None]
        
    arestas_trace = go.Scatter(
        x=arestas_x, y=arestas_y,
        line=dict(width=0.5, color='#888'),
        hoverinfo='none',
        mode='lines'
    )

    nos_x = []
    nos_y = []
    textos = []
    for node in grafo.nodes():
        x, y = pos[node]
        nos_x.append(x)
        nos_y.append(y)
        textos.append(str(node))

    nos_trace = go.Scatter(
        x=nos_x, y=nos_y,
        mode='markers+text',
        text=textos,
        textposition="bottom center",
        marker=dict(
            showscale=True,
            colorscale='YlGnBu',
            size=10,
        )
    )

    layout = go.Layout(
        title="Visualização Interativa do Grafo",
        showlegend=False,
        hovermode='closest',
        margin=dict(b=20, l=5, r=5, t=40),
        xaxis=dict(showgrid=False, zeroline=False, showticklabels=False),
        yaxis=dict(showgrid=False, zeroline=False, showticklabels=False)
    )

    fig = go.Figure(data=[arestas_trace, nos_trace], layout=layout)
    fig.show()

def main():
    grafo = carregar_grafo('Grafo-com-youtube.ungraph.txt')
    
    if nx.is_connected(grafo):
        subgrafo = grafo
    else:

        componentes = list(nx.connected_components(grafo))
        componente_maior = max(componentes, key=len)
        subgrafo = grafo.subgraph(componente_maior)

    propriedades_grafo(subgrafo)

    grau_nos = sorted(subgrafo.degree, key=lambda x: x[1], reverse=True)
    top_50_nos = [no for no, grau in grau_nos[:50]]
    
    subgrafo_top_50 = subgrafo.subgraph(top_50_nos)

    propriedades_grafo(subgrafo_top_50)

    visualizar_grafo(subgrafo_top_50)

if __name__ == "__main__":
    main()
