#include "player.h"

player::player()
{
    texture.loadFromFile("gfx/rainbow_man.png");
    setSize(sf::Vector2f(105, 110));
    setPosition(100, 100);
    setTexture(&texture);
    setCollisionBox(0, 0, 95, 110);

    idle.addFrame(sf::IntRect(21, 0, 21, 22));

    run.addFrame(sf::IntRect(21, 0, 21, 22));
    run.addFrame(sf::IntRect(0, 0, 21, 22));
    run.addFrame(sf::IntRect(63, 0, 21, 22));
    run.addFrame(sf::IntRect(42, 0, 21, 22));
    run.setFrameSpeed(1.f / 10.f);


    slide.addFrame(sf::IntRect(0, 24, 21, 23));
    slide.addFrame(sf::IntRect(0, 24, 21, 23));
    slide.addFrame(sf::IntRect(0, 24, 21, 23));
    slide.setLooping(true);
    slide.setFrameSpeed(1.f / 5.f);

    currentAnimation = &idle;

    scale = 200.f;

    gravity = sf::Vector2f(0, 9.8f) * scale;

   
}

player::~player()
{

}

void player::life()
{
    second_check = true;
}

void player::update(float dt)
{
    speed = 300.f;
    check = false;
    setTextureRect(currentAnimation->getCurrentFrame());
    //setCollisionBox(0, 0, 85, 110);

    if (run.getFlipped() == true)
    {
        idle.setFlipped(true);
        slide.setFlipped(true);
    }
    else if (run.getFlipped() == false)
    {
        idle.setFlipped(false);
        slide.setFlipped(false);
    }

    sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
    stepVelocity += gravity * dt;
    setPosition(getPosition() + pos);

    if (getPosition().y >= 740)
    {
        setPosition(getPosition().x, 740);
        stepVelocity = sf::Vector2f(0, 0);
    }

}

void player::handleInput(float dt)
{
    if (input->isKeyDown(sf::Keyboard::Up) == true && stepVelocity.y == 0)
    {
        if (stepVelocity.y != 0)
        {
            input->setKeyUp(sf::Keyboard::Up);
        }

        stepVelocity = sf::Vector2f(0, -4.f) * scale;

        if (stepVelocity == zero)
        {
            currentAnimation = &idle;
            input->setKeyUp(sf::Keyboard::Up);
        }

    }

    if (input->isKeyDown(sf::Keyboard::Right))
    {
        currentAnimation = &run;
        run.animate(dt);
        run.setFlipped(false);
        move(speed * dt, 0);
        setCollisionBox(0, 0, 95, 110);
    }
    else if (input->isKeyDown(sf::Keyboard::Left))
    {
        currentAnimation = &run;
        run.animate(dt);
        run.setFlipped(true);
        move(-speed * dt, 0);
        setCollisionBox(0, 0, 95, 110);
    }
    else
    {
        currentAnimation = &idle;
    }

    if (input->isKeyDown(sf::Keyboard::Down) == true)
    {
        input->setKeyDown(sf::Keyboard::Down);
        slide.animate(dt);
        currentAnimation = &slide;
        setCollisionBox(0, 20, 100, 90);

    }

}

void player::collision_resp_tile(GameObject* collider)
{
    if (abs(getPosition().x  - collider->getPosition().x) > abs(getPosition().y - collider->getPosition().y))
    {
        speed = 0.f;
        if( run.getFlipped() == false) { setPosition(getPosition().x - 2, getPosition().y);}
        else { setPosition(getPosition().x + 2, getPosition().y); }
        check = true;
        
    }
    else if (abs(getPosition().x - collider->getPosition().x) < abs(getPosition().y - collider->getPosition().y))
    {
        
        
            if (getPosition().y < collider->getPosition().y)
            {
                stepVelocity.y = 0;
                if (check == false) { setPosition(getPosition().x, collider->getPosition().y - getSize().y); }
               
            }
            else
            {
                stepVelocity = sf::Vector2f(0, 4.f) * scale;
                setPosition(getPosition().x, getPosition().y + 1);
            }
        
    }
    
}

void player::collision_resp_enemy(GameObject* collider)
{
    if (abs(getPosition().x - collider->getPosition().x) < abs(getPosition().y - collider->getPosition().y))
    {
        if (getPosition().y < collider->getPosition().y)
        {
            stepVelocity = sf::Vector2f(0, -4.f) * scale;
        }
        else
        {
            if (second_check == true)
            {
                setPosition(getPosition().x - 200, 0);
                second_check = false;
            }
            else
            {
                setPosition(100, 0);
            }
           
        }
    }
    else
    {
        if (second_check == true)
        {
            setPosition(getPosition().x - 200, 0);
            second_check = false;
        }
        else
        {
            setPosition(100, 0);
        }
    }
}

void player::collision_resp_pickup(GameObject* collider)
{
   
}

