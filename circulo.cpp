//
// Created by rodrigo on 28/07/25.
//

#include "circulo.h"
#include "game.h"
#include "Force.h"


/////////////////////////////////////////
/// circle
///
circle::circle(const int &x, const int &y, const int &radio, const int& masa) : x(x), y(y), radio(radio) {
    m_particula = new particula(x, y, masa, radio);
    gravedad = Vec2r(0, 9.81f * PIXELS_POR_METRO); // gravedad en pixeles por metro
    peso = gravedad * m_particula->getMasa() ; // el peso se cancela con la masa F = m*a;

}

void circle::draw() {
    filledCircleColor(TheGame::getInstance()->getRenderer(), m_particula->getPosition().getX(),
        m_particula->getPosition().getY(), radio, 0xff000000);
}

void circle::update() {

    // integra la aceleración con la velocidad  para encontrar la nueva posición
    /*m_particula->addForces(peso);
    m_particula->addForces(Vec2r(190, 0)); // viento
    if (m_particula->getPosition().getY() >= TheGame::getInstance()->get_Alto()/2) {
        Vec2r dragFroce = TheForce::getInstance()->GenerateDragForce(*m_particula, 0.008f);
        m_particula->addForces(dragFroce); //
    }*/


    //m_particula->addForces(TheGame::getInstance()->get_PushForce()); // fuerza de empuje con el teclado
    //Vec2r frictionForce = TheForce::getInstance()->GenerateFrictionForce(*m_particula, 5.0f * PIXELS_POR_METRO); // fuerza de fricción
    //  *dynamic_cast<circle *>(*it)->getParticula() TIPO DE DYNAMIC CAST
    float uno = -1.0f;  //TODO: encontrar una mejor forma
    for (std::vector<ObjetoAbstractoBase *>::size_type i = 0; i < TheGame::m_players.size(); ++i) {
        if (TheGame::m_players[i] == this)
            break;
        uno *= uno;
    }

    for (std::vector<ObjetoAbstractoBase *>::size_type i = 0; i < TheGame::m_players.size(); ++i) {
        if (TheGame::m_players[i] != this) {
            particula* otra_particula = dynamic_cast<circle *>(TheGame::m_players[i])->getParticula();
            Vec2r gravForce = TheForce::getInstance()->GenerateGravitationalForce(*m_particula, *otra_particula, 4.5f);

            m_particula->addForces(gravForce * uno ); // fuerza gravitacional entre las partículas
            uno *= uno;
        }
    }

    //m_particula->addForces(TheForce::getInstance()->GenerateGravitationalForce(*m_particula, *m_otra_particula, 1.0f) * nFactor); //
    m_particula->integrate(TheGame::deltaTime);


    // colisiones con los bordes de la pantalla
    // solo un truco que no tiene relación con lo demás, pero sirve para testear las funciones creadas
    if ((m_particula->getPosition().getX() - radio) <= 0) {
        m_particula->setPosX(radio);
        m_particula->setVelocity(m_particula->getVelocity() * Vec2r(-0.8, 0.8));

    } else if ((m_particula->getPosition().getX() + radio) >= TheGame::getInstance()->get_Ancho()) {
        m_particula->setPosX(TheGame::getInstance()->get_Ancho() - radio);
        m_particula->setVelocity(m_particula->getVelocity() * Vec2r(-0.8, 0.8));
    }
    if ((m_particula->getPosition().getY() - radio) <= 0) {
        m_particula->setPosY(radio);
        m_particula->setVelocity(m_particula->getVelocity() * Vec2r(0.8, -0.8));

    } else if ((m_particula->getPosition().getY() + radio) >= TheGame::getInstance()->get_Alto()) {
        m_particula->setPosY(TheGame::getInstance()->get_Alto() - radio);
        m_particula->setVelocity(m_particula->getVelocity() * Vec2r(0.8, -0.8));
    }
}

particula * circle::getParticula() {

    return m_particula;
}


///////////////////////////////////////////////////
///

rectangulo::rectangulo(const int &x, const int &y, const int &width, const int &height, const Uint32& color)
: x(x), y(y), width(width), height(height), color(color) {
    blue = 0;

}


void rectangulo::draw() {
    boxColor(TheGame::getInstance()->getRenderer(), x + width, y,
        x, y + height, color);

}

void rectangulo::update() {
/*
        blue+=1;
        color &= ((blue%255) << 16);*/
}

void rectangulo::clean() {
}

void rectangulo::DrawFillRect() const {

}


