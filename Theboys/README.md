# 🌟 Projeto The Boys - Simulação de Heróis, Bases e Missões 🦸‍♂️🦸‍♀️

Este projeto foi inspirado na série *The Boys* e visa simular um mundo repleto de heróis, bases e missões utilizando o conceito de **Simulação a Eventos Discretos (SED)**.

---

## 📝 Descrição do Projeto

Este projeto consiste em simular a dinâmica de heróis que possuem habilidades específicas, se movimentam entre bases, participam de missões e acumulam experiência. O sistema é modelado através de eventos discretos que ocorrem ao longo do tempo, representando ações como:

- Chegada de heróis a bases;
- Decisões sobre esperar em filas ou viajar para outra base;
- Execução de missões em locais aleatórios;
- Ganho de experiência ao completar missões.

A simulação ocorre durante **525.600 minutos**, o equivalente a um ano, e ao final apresenta estatísticas detalhadas sobre o desempenho dos heróis e a execução das missões.

---

## 🚀 Como foi desenvolvido

O projeto foi desenvolvido utilizando os seguintes conceitos e técnicas:

1. **Simulação a Eventos Discretos (SED):**
   - Estrutura estática: entidades como heróis, bases e missões com seus atributos.
   - Estrutura dinâmica: evolução do sistema através de eventos agendados em uma **Lista de Eventos Futuros (LEF)**.

2. **Modelagem de Entidades:**
   - **Heróis**: Possuem habilidades, paciência, velocidade e experiência.
   - **Bases**: Localizadas em um plano cartesiano, com limite de lotação e filas de espera.
   - **Missões**: Requerem habilidades específicas e são realizadas por equipes formadas em bases.

3. **Eventos Principais:**
   - `CHEGA`: Herói chega a uma base.
   - `ESPERA`: Herói entra na fila de espera.
   - `DESISTE`: Herói decide viajar para outra base.
   - `MISSAO`: Missão ocorre e verifica qual base está apta a realizá-la.
   - `FIM`: Relatório final da simulação.

4. **Algoritmos e Estruturas:**
   - Implementação de fila para gerenciar as filas de espera nas bases.
   - Utilização de listas ordenadas para a **LEF**.
   - Modelagem matemática para cálculo de distâncias entre bases e habilidades necessárias.

---

## 📊 Resultados Esperados

### Exemplo de Relatório Final:
```plaintext
525600: FIM
HEROI  0 PAC  32 VEL 3879 EXP  441 HABS [ 2 9 ]
HEROI  1 PAC  52 VEL 2974 EXP  620 HABS [ 5 ]
...
HEROI 49 PAC  84 VEL  522 EXP  510 HABS [ 4 ]
MISSOES CUMPRIDAS: 5236/5256 (99.62%)
TENTATIVAS/MISSAO: MIN 1, MAX 21, MEDIA 2.08
``` 

`Heróis:` Estatísticas de cada herói ao final da simulação, incluindo experiência acumulada e habilidades.

`Missões:` Taxa de sucesso, número de tentativas por missão e porcentagem de missões concluídas.

### 🧩 Estruturas do Código

1. **Bibliotecas e Configurações Gerais**
   - Inclui as bibliotecas necessárias, como `stdio.h`, `math.h` e outras.
   - Define constantes globais importantes, como `T_FIM_DO_MUNDO` e `N_HABILIDADES`.

2. **Definições de Estruturas**
   - Define as estruturas que representam as entidades principais:
     - `heroi_t`: Estrutura de um herói, incluindo ID, paciência, habilidades, etc.
     - `base_t`: Estrutura de uma base, com lotação, fila de espera, e localização.
     - `missao_t`: Estrutura de uma missão, com habilidades requeridas e localização.
     - `mundo_t`: Estrutura que engloba todas as entidades, incluindo heróis, bases e missões.

3. **Funções Auxiliares**
   - Funções que realizam tarefas gerais e cálculos, como:
     - Geração de números aleatórios (`aleat`).
     - Cálculo de distâncias.
     - Ordenação de bases pela proximidade com missões.

4. **Inicialização**
   - Funções para criar e inicializar:
     - Heróis: atribui paciência, habilidades e velocidade.
     - Bases: define localização, lotação e cria filas de espera.
     - Missões: configura habilidades e localizações aleatórias.
     - Mundo: junta heróis, bases e missões.

5. **Eventos**
   - Funções que tratam os eventos do simulador, como:
     - **CHEGA**: Quando um herói chega em uma base.
     - **ESPERA**: Quando um herói entra na fila de espera.
     - **DESISTE**: Quando um herói desiste de entrar na base e viaja para outra.
     - **MISSAO**: Quando uma missão é disparada.
     - **FIM**: Finaliza a simulação e gera relatórios.

6. **Simulação**
   - Funções principais que:
     - Processam a Lista de Eventos Futuros (LEF).
     - Atualizam o estado do mundo.
     - Tratam eventos em sequência, como missões e movimentações.

7. **Relatórios**
   - Gera relatórios ao final da simulação:
     - Estatísticas dos heróis (experiência, habilidades, etc.).
     - Percentual de missões concluídas.
     - Média de tentativas por missão.

8. **Gerenciamento de Memória**
   - Funções para destruir e liberar memória alocada:
     - Liberação de heróis, bases e missões.
     - Limpeza de filas e conjuntos.
     - Finalização do mundo.

## 🛠️ Fluxo do Programa

1. **Inicialização**
   - Configura heróis, bases e missões.
   - Agenda eventos iniciais na Lista de Eventos Futuros (LEF).

2. **Simulação**
   - Processa eventos em ordem cronológica:
     - Atualiza estado das entidades.
     - Agrega novos eventos à LEF.

3. **Finalização**
   - Exibe resultados.
   - Libera memória alocada.


Simulação:
simulacao.c / simulacao.h: Gerencia o relógio global e a execução da LEF.
Eventos:
eventos.c / eventos.h: Implementa os eventos como CHEGA, ESPERA, SAI, VIAJA e outros.

### 2. Funções Importantes

Inicialização: Configuração inicial do mundo, heróis, bases e missões.
Processamento da LEF: Processamento sequencial dos eventos agendados.
Relatórios: Geração de relatórios ao final da simulação.

### 3. Principais Estruturas de Dados

Lista ordenada para LEF.
Fila para heróis aguardando em bases.
Vetores para armazenamento de heróis, bases e missões.

## ⚙️ Como Executar

### Pré-requisitos:
- Compilador **C** (ex: `gcc`).
- Sistema **Unix/Linux** recomendado.
- Ferramenta de análise de memória como **Valgrind** para depuração.

### Passos:

1. Clone o repositório:
   ```bash
   git clone git@github.com:ricardobacano/Programação1.git
   ``` 

2. Compile o projeto:
   ```bash
   make 
   ``` 
3. Execute a simulação:
   ```bash
   ./theboys
   ```
   
Opcional: Analise a execução com Valgrind:
   ```bash
   valgrind --leak-check=full ./theboys
   ``` 

