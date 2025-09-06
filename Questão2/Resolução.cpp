#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> grafo(n);
        vector<int> grau_entrada(n, 0);

        for (const auto& relacao : relations) {
            int curso_anterior = relacao[0] - 1;
            int proximo_curso = relacao[1] - 1;
            grafo[curso_anterior].push_back(proximo_curso);
            grau_entrada[proximo_curso]++;
        }

        vector<int> tempo_final_curso(n, 0);
        queue<int> fila;

        for (int i = 0; i < n; ++i) {
            if (grau_entrada[i] == 0) {
                fila.push(i);
                tempo_final_curso[i] = time[i];
            }
        }

        while (!fila.empty()) {
            int curso_atual = fila.front();
            fila.pop();

            for (int proximo_curso_dependente : grafo[curso_atual]) {
                tempo_final_curso[proximo_curso_dependente] = max(
                    tempo_final_curso[proximo_curso_dependente],
                    tempo_final_curso[curso_atual] + time[proximo_curso_dependente]
                );

                grau_entrada[proximo_curso_dependente]--;

                if (grau_entrada[proximo_curso_dependente] == 0) {
                    fila.push(proximo_curso_dependente);
                }
            }
        }

        return *max_element(tempo_final_curso.begin(), tempo_final_curso.end());
    }
};