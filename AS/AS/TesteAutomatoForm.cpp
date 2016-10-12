#include "TesteAutomatoForm.h"

using namespace AS;

int TesteAutomatoForm::getStatus(){
	return Status;
}

void TesteAutomatoForm::setStatus(int valor){
	Status = valor;
}

string TesteAutomatoForm::getPalavra(){
	string Palavra;

	MarshalString(textBox1->Text, Palavra);

	return Palavra;
}


void TesteAutomatoForm::setLabel(string label){
	String ^ Texto = gcnew String(label.c_str());
	label1->Text = Texto;
	delete(Texto);
}

void TesteAutomatoForm::setImagemEstado(string caminho){

	String ^ path = gcnew String(caminho.c_str());
	pictureBox1->Image = Image::FromFile(path);
	delete(path);
}

void TesteAutomatoForm::setProxEstado(bool valor){
	proxEstado = valor;
}

bool TesteAutomatoForm::getProxEstado(){
	return proxEstado;
}

void TesteAutomatoForm::setAF(int op){
	Automato AF;
	switch  (op){
	case 1:
		af = AF.automato1();
		setImagemEstado(af->imagemInicial);
		break;
	}
}

void TesteAutomatoForm::sleepcp(int milliseconds) // cross-platform sleep function
{
	clock_t time_end;
	time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
	while (clock() < time_end)
	{
	}
}

bool TesteAutomatoForm::testeAutomato1(string palavra){
	ponteiro aux = af;
	int i, j;
	bool resultado = true;

	setImagemEstado(aux->imagem);
	sleepcp(1000);

	for (i = 0; i < palavra.size(); i++){
		for (j = 0; j < 10; j++){
			if (aux->transicoes[j].simboloAceito == palavra[i]){
				
				//while (!getProxEstado()){
				//}
				aux = aux->transicoes[j].link;
				setImagemEstado(aux->imagem);
				sleepcp(1000);
				break;
			}
		}
		if (j == 10){
			resultado = false;
			break;
		}
	}
	if (resultado && aux->isFinal == false){
		resultado = false;
	}
	return resultado;

}

