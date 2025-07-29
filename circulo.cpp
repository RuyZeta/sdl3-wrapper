//
// Created by rodrigo on 28/07/25.
//

#include "circulo.h"
#include "game.h"


/////////////////////////////////////////
/// circle
///
circle::circle(const int &x, const int &y, const int &radio, const int& masa) : x(x), y(y), radio(radio) {
    m_particula = new particula(x, y, masa);
    gravedad = Vec2r(0, 9.81f * PIXELS_POR_METRO); // gravedad en pixeles por metro
    peso = gravedad * m_particula->getMasa() ; // el peso se cancela con la masa F = m*a;
}

void circle::draw() {
    filledCircleColor(TheGame::getInstance()->getRenderer(), m_particula->getPosition().getX(),
        m_particula->getPosition().getY(), radio, 0xff000000);
}

void circle::update() {

    // integra la aceleración con la velocidad  para encontrar la nueva posición
    m_particula->addForces(peso);
    m_particula->addForces(Vec2r(190, 0)); // viento
    m_particula->integrate(TheGame::deltaTime);

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
