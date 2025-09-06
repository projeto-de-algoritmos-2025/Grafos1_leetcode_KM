###  2050. Parallel Courses III

**Descrição:**
Você recebe um inteiro n, que indica que existem n cursos numerados de 1 a n. Você também recebe um array de inteiros 2D chamado relations, onde relations[j] = [cursoAnteriorj, proximoCursoj] denota que o curso cursoAnteriorj deve ser concluído antes do curso proximoCursoj (uma relação de pré-requisito). Além disso, você recebe um array de inteiros time com índice baseado em zero, onde time[i] denota quantos meses leva para concluir o (i+1)-ésimo curso.

Você deve encontrar o número mínimo de meses necessários para concluir todos os cursos, seguindo estas regras:

Você pode começar a fazer um curso a qualquer momento, desde que os pré-requisitos sejam atendidos.

Qualquer número de cursos pode ser feito ao mesmo tempo.

Retorne o mínimo de meses necessários para completar todos os cursos.

**Nota:** Os casos de teste são gerados de tal forma que é possível completar todos os cursos (ou seja, o grafo é um grafo acíclico dirigido).