# 🌟 Projeto The Boys - Simulação de Heróis, Bases e Missões 🦸‍♂️🦸‍♀️

Este projeto foi inspirado na série *The Boys* e visa simular um mundo repleto de heróis, bases e missões utilizando o conceito de **Simulação a Eventos Discretos (SED)**. Desenvolvido originalmente pelos professores **Fabiano Silva**, **Luis Bona** e **Marcos Castilho**, aqui apresentamos uma versão adaptada do projeto.

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
   - Utilização de árvores ou listas ordenadas para a **LEF**.
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

## 🛠️ Estrutura do Código

###1. Módulos Principais
Entidades:

heroi.c / heroi.h: Manipula os atributos dos heróis.
base.c / base.h: Gerencia as bases, filas e heróis presentes.
missao.c / missao.h: Define missões e verifica a aptidão de equipes.
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
