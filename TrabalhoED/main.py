import tkinter as tk
from tkinter import scrolledtext, messagebox
import networkx as nx

def carregar_grafo(arquivo):
    grafo = nx.read_edgelist(arquivo, create_using=nx.Graph(), nodetype=str)
    return grafo

def maiores_influenciadores(grafo):
    grau = grafo.degree()
    influenciadores = sorted(grau, key=lambda x: x[1], reverse=True)[:10] 
    return influenciadores

def menor_influenciador(grafo):
    grau = grafo.degree()
    menor = min(grau, key=lambda x: x[1])
    return menor

def usuario_mais_inscrito(grafo):
    grau = grafo.degree()
    mais_inscrito = max(grau, key=lambda x: x[1])
    return mais_inscrito

def usuario_menos_inscrito(grafo):
    grau = grafo.degree()
    menos_inscrito = min(grau, key=lambda x: x[1])
    return menos_inscrito

def usuarios_com_interesses_comuns(grafo):
    comunidades = {}
    for usuario in grafo.nodes:
        canais = set(grafo.neighbors(usuario))
        comunidades[usuario] = canais

    top_usuarios = sorted(comunidades.items(), key=lambda x: len(x[1]), reverse=True)[:10]

    resultado = ""
    for usuario, canais in top_usuarios:
        resultado += f"Usuário: {usuario}, Interesses Comuns (Canais): {len(canais)}\n"
    
    return resultado

def canais_com_publicos_semelhantes(grafo):
    canais = {}
    for usuario in grafo.nodes:
        for canal in grafo.neighbors(usuario):
            if canal not in canais:
                canais[canal] = set()
            canais[canal].add(usuario)

    top_canais = sorted(canais.items(), key=lambda x: len(x[1]), reverse=True)[:10]
    
    resultado = ""
    for canal, usuarios in top_canais:
        resultado += f"Canal: {canal}, Público Semelhante (Usuários): {len(usuarios)}\n"
    
    return resultado

def distribuicao_inscritos(grafo):
    grau = dict(grafo.degree())
    media_inscritos = sum(grau.values()) / len(grau)
    abaixo_media = {k: v for k, v in grau.items() if v < media_inscritos}
    acima_media = {k: v for k, v in grau.items() if v > media_inscritos}

    abaixo_media_top10 = dict(sorted(abaixo_media.items(), key=lambda x: x[1])[:10])
    acima_media_top10 = dict(sorted(acima_media.items(), key=lambda x: x[1], reverse=True)[:10])
    
    return media_inscritos, abaixo_media_top10, acima_media_top10

def mostrar_resultado(texto):
    resultado_texto.delete(1.0, tk.END)
    resultado_texto.insert(tk.END, texto)

def executar_opcao(opcao, grafo):
    if opcao == '10 Maiores Influenciadores':
        resultado = "Top 10 Maiores Influenciadores:\n"
        influenciadores = maiores_influenciadores(grafo)
        for i, influenciador in enumerate(influenciadores, start=1):
            resultado += f"{i}. {influenciador[0]} - {influenciador[1]} inscritos\n"
    elif opcao == 'Canal com Menor Número de Inscritos':
        resultado = "Canal com Menor Número de Inscritos:\n"
        menor = menor_influenciador(grafo)
        resultado += f"{menor[0]} - {menor[1]} inscritos\n"
    elif opcao == 'Usuário Inscrito no Maior Número de Canais':
        resultado = "Usuário Inscrito no Maior Número de Canais:\n"
        mais_inscrito = usuario_mais_inscrito(grafo)
        resultado += f"{mais_inscrito[0]} - {mais_inscrito[1]} canais\n"
    elif opcao == 'Usuário Inscrito no Menor Número de Canais':
        resultado = "Usuário Inscrito no Menor Número de Canais:\n"
        menos_inscrito = usuario_menos_inscrito(grafo)
        resultado += f"{menos_inscrito[0]} - {menos_inscrito[1]} canais\n"
    elif opcao == 'Usuários com Interesses Comuns':
        resultado = "Usuários com Interesses Comuns (Top 10):\n"
        resultado += usuarios_com_interesses_comuns(grafo)
    elif opcao == 'Canais com Públicos Semelhantes':
        resultado = "Canais com Públicos Semelhantes (Top 10):\n"
        resultado += canais_com_publicos_semelhantes(grafo)
    elif opcao == 'Distribuição de Inscritos por Canal':
        media, abaixo, acima = distribuicao_inscritos(grafo)
        resultado = (f"Distribuição de Inscritos por Canal:\n"
                     f"Média de Inscritos: {media:.2f}\n"
                     f"Canais com Inscritos Abaixo da Média:\n")
        for canal, inscritos in abaixo.items():
            resultado += f"{canal} - {inscritos} inscritos\n"
        resultado += f"Canais com Inscritos Acima da Média:\n"
        for canal, inscritos in acima.items():
            resultado += f"{canal} - {inscritos} inscritos\n"
    else:
        resultado = "Opção inválida."

    mostrar_resultado(resultado)

def main():
    grafo = carregar_grafo('Grafo-com-youtube.ungraph.txt')

    global resultado_texto
    janela = tk.Tk()
    janela.title("Análise de Canais do YouTube")
    janela.configure(bg="#1E1E1E")

    menu = tk.Frame(janela, bg="#2F2F2F")
    menu.pack(pady=10, padx=10)

    opcoes = [
        '10 Maiores Influenciadores',
        'Canal com Menor Número de Inscritos',
        'Usuário Inscrito no Maior Número de Canais',
        'Usuário Inscrito no Menor Número de Canais',
        'Usuários com Interesses Comuns',
        'Canais com Públicos Semelhantes',
        'Distribuição de Inscritos por Canal'
    ]

    for opcao in opcoes:
        botao = tk.Button(menu, text=opcao, command=lambda opcao=opcao: executar_opcao(opcao, grafo), 
                          bg="#0078D4", fg="white", font=("Helvetica", 12), relief="flat", bd=0, padx=10, pady=10)
        botao.pack(fill=tk.X, padx=5, pady=5)

    resultado_texto = scrolledtext.ScrolledText(janela, width=60, height=20, bg="#2B2B2B", fg="white", font=("Helvetica", 11))
    resultado_texto.pack(padx=10, pady=10)

    sair_botao = tk.Button(janela, text="Sair", command=janela.quit, bg="#D32F2F", fg="white", font=("Helvetica", 12), relief="flat", bd=0, padx=15, pady=10)
    sair_botao.pack(pady=10)

    janela.mainloop()

if __name__ == "__main__":
    main()
