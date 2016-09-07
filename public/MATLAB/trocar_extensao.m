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
