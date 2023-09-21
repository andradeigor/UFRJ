## Resultado do Programa do Laboratório Base:
| Nº Threads | Execução 1 (s) | Execução 2 (s) | Execução 3 (s) | Média (s)|
|--- |--- |--- |--- |--- |
| 1 | 1.142843 | 1.145996 |1.160094 |1,149644 |
| 2 | 2.810694 | 2.869131 |2.892073 |2,857299 |

## Resultado do Programa do Laboratório com Leitores e Escritores:

| Nº Threads | Execução 1 (s) | Execução 2 (s) | Execução 3 (s) | Média (s)|
|--- |--- |--- |--- |--- |
| 1 | 1.160105 | 1.158452 |1.175052 |1.164536 |
| 2 | 1.819625 | 1.844125 |1.850884 |1.838211 |


## Resultado do Meu Programa:

| Nº Threads | Execução 1 (s) | Execução 2 (s) | Execução 3 (s) | Média (s)|
|--- |--- |--- |--- |--- |
| 1 | 1.347123 | 1.345243 |1.344441 |1,345602 |
| 2 | 2.503359 | 2.504293 |2.512271 |2,506641 |

## Análise
Vemos que claramente os leitores e escritores desenvolvidos pela biblioteca são bem melhores que os que feitos por mim, mas isso já era de se esperar. Entretanto, tivemos mesmo que pequena uma melhora na paralelização quando comparadas ao programa base, o que mostra que de fato o meu programa está sendo mais eficiente do que a exclusão mútua. Outro detalhe que vale apontar é que eu obtive uma boa melhora quando implementei a prioridade para os escritores, na qual quando um escritor está na fila para escrever, novos leitores não pode entrar.