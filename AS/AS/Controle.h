#pragma once
#ifndef ControleH
#define ControleH

#include <iostream>
using namespace std;
#include <string>
#include "MenuAS.h"
#include "FormListaAutomato.h"
#include "TesteAutomatoForm.h"
#include "SobreAutomato1Form.h"
#include "Automato.h"
#include "SobreAs.h"
#include "TesteAutomatoPorta.h"
#include "TesteAutomatoTorneira.h"
#include "SobreAutomato4.h"
#include "SobreAutomato2Form.h"
#include "SobreAutomato3Form.h"
#include "SobreAutomato5Form.h"



using namespace System;
using namespace System::Windows::Forms;

class Controle {
private:
	bool Resposta;
public:
	Controle();
	~Controle();
	void controlarExecucao(void);
};
#endif

