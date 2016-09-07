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
% Controle de fluxo
disp('# CONTROLE DE FLUXO');
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
    % vetor(limite) = vetor(limite-1) + vetor(limite-2);
    vetor(limite) = sum(vetor((limite-2):(limite-1)));
end
vetor
vetor(2:5)
texto = 'yo';
switch texto
case 'yo'
    disp('dawg');
case 'ola'
    disp('Tudo bem?');
otherwise
    disp('i dont get you')
end

disp('# ARQUIVOS');
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
    fprintf('%s\n', linha);
    linha = fgetl(fp);
end
fclose(fp);
linha

% Distribuicao
disp('# DISTRIBUICAO')
nome = 'abestado';
fprintf('diga oi para %s: %s\n', nome, diga_oi(nome));
arquivo = 'intro.md';
novo_arquivo = trocar_extensao(arquivo, 'txt');
fprintf('%s agora eh %s #sqn\n', arquivo, ...
                                 novo_arquivo);
