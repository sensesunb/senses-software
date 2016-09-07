Introdução ao MATLAB
====================

MATLAB é uma linguagem de programação interpretada, fraca e dinamicamente tipada, multi-paradigma (imperativa, estruturada, orientada a objetos e funcional, tudo ao mesmo tempo) e voltada para cálculo numérico. Os scripts de MATLAB rodam em Java, e são responsáveis não somente pela parte matemática, mas também pelo GUIDE e pelo Simulink.

Tipos básicos
-------------

``` matlab
% Eu sou um comentario!
% # Tipos basicos
eu_sou_verdadeiro = true
eu_sou_falso = false
funcao_e = and(eu_sou_verdadeiro, eu_sou_falso)
funcao_ou = or(eu_sou_verdadeiro, eu_sou_falso)
% help and
sou_um_numero = 5
sou_outro_numero = 13
sou_imaginario = 7 - 3i
soma = sou_um_numero + sou_outro_numero
produto = sou_outro_numero * sou_imaginario
divisao = sou_um_numero / sou_outro_numero
matriz = [ ]
matriz(1) = sou_um_numero
matriz(2,2) = sou_imaginario
length(matriz)
size(matriz)
texto = 'somente com aspas simples!'
ola = 'hello'
nome = 'joe frank'
saudacao = strcat(ola, ' ', nome)
disp(saudacao)
fprintf('fprintf: %s %s\n', ola, nome)
saudacao = sprintf('%s %s\n', ola, nome)
disp(saudacao)
x = -pi:0.1:pi
x = -pi:0.1:pi;
y = sin(x);
z = cos(x .^ 2);
figure;
plot(x, y);
figure;
plot(x, z);
figure;
plot(x, y, 'b', ...
     x, z, 'r-');
```

Controle de fluxo
-----------------

``` matlab
if funcao_e
    texto = 'V e F = V';
elseif funcao_ou
    texto = 'V ou F = V';
else
    texto = 'Nada a ver';
end
disp(texto);
x = 1;
while x <= 10
    fprintf('while %d\n', x);
    x = x + 1;
end
for x = 1:10
    fprintf('for %d\n', x);
end
for x = 1:2:16
    fprintf('another for %d\n', x);
end
vetor = [1 1];
for x = 1:10
    limite = length(vetor) + 1;
    vetor(limite) = vetor(limite-1) + vetor(limite-2);
end
vetor
texto = 'yo';
switch texto
case 'yo'
    disp('dawg');
case 'ola'
    disp('Tudo bem?');
otherwise
    disp('i dont get you')
end
```

Arquivos
--------

```
% Células
celula = { };
celula{1} = 'joe frank';
celula{2} = 22;

% Arquivos
fp = fopen('dados.txt', 'w');
for n = 1:length(celula)
    fprintf(fp, '%s\n', celula{n});
end
fclose(fp);
fp = fopen('dados.txt', 'r');
linha = fgetl(fp);
while ischar(linha)
    fprintf('%s\n', linha)
    linha = fgetl(fp);
end
fclose(fp);
linha

```

Distribuição
------------

Crie um arquivo chamado `diga_oi.m` na mesma pasta do script principal:

```
%% diga_oi: Diz ola para o nome dado!
function [saida] = diga_oi(nome)
% Diz ola para o nome dado!
saida = sprintf('oi %s!', nome);
```

E crie um arquivo chamado `trocar_extensao.m` na mesma pasta:

```
%% trocar_extensao: troca a extensao de um arquivo
function [saida] = trocar_extensao(entrada, ext_nova)
% troca a extensao de um arquivo
onde = loop_trocar_extensao(entrada, length(entrada));
saida = strcat(entrada(1:onde), ext_nova);

%% loop_trocar_extensao: loop da funcao trocar extensao para descobrir onde a extensao termina
function [indice] = loop_trocar_extensao(entrada, indice)
% loop da funcao trocar extensao para descobrir onde a extensao termina
if ~isequal(entrada(indice), '.')
    indice = loop_trocar_extensao(entrada, indice-1);
end
```

A saber, este é o script principal:

```
disp('# DISTRIBUICAO')
nome = 'abestado';
fprintf('diga oi para %s: %s\n', nome, diga_oi(nome));
arquivo = 'intro.md';
novo_arquivo = trocar_extensao(arquivo, 'txt');
fprintf('%s agora eh %s #sqn\n', arquivo, novo_arquivo);
```

Simulink
--------

Pacote para simulação de sistemas físicos por meio de bloquinhos! Muito útil.

GUIDE
-----

Pacote para criação de interfaces gráficas! Muito feio, mas é simples de usar.
