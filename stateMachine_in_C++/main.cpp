#include<iostream>
/*
    state'ler:
    Idle
    Walking
    Running
    Jumping

    Eventler:
    Move
    Stop
    Run
    Jump
    Land
*/


enum class State{
//player ın bulunabileceği tüm durumları burada tanımlıyoruz.
    Idle,
    Walking,
    Running,
    Jumping
};

enum class Event
{
    //State değişimini eventler tetikler.
    //sisteme gelebilecek olaylar.Sensörlerden klavyeden yada yazılımsal olarak(timer vb.)gelebilir.
    Move,
    Stop,
    Run,
    Jump,
    Land

};
// currentState + Event = new state

//Event bekle gelen event ve şu anki state e göre karar ver.
class PlayerFSM
{
    private:
    State currentState;

    public:
    PlayerFSM()
    {
        currentState = State::Idle;
    }

    void handleEvent(Event event)
    {
        switch(currentState)
        {
            case State::Idle:
                handleIdle(event);
                break;
             case State::Walking:
                handleWalking(event);
                break;

            case State::Running:
                handleRunning(event);
                break;

            case State::Jumping:
                handleJumping(event);
                break;
        }
    }
    
    void handleIdle(Event event)
    {
        switch(event)
        {
            case Event::Move:
                transitionTo(State::Walking);
                break;

            case Event::Jump:
                transitionTo(State::Jumping);
                break;

            default:
                break;
        }
    }
    
    void handleWalking(Event event)
    {
        switch(event)
        {
            case Event::Stop:
                transitionTo(State::Idle);
                break;

            case Event::Run:
                transitionTo(State::Running);
                break;

            case Event::Jump:
                transitionTo(State::Jumping);
                break;

            default:
                break;
        }
    }
    
    void handleRunning(Event event)
    {
        switch(event)
        {
            case Event::Stop:
                transitionTo(State::Idle);
                break;

            case Event::Jump:
                transitionTo(State::Jumping);
                break;

            default:
                break;
        }
    }
    
    void handleJumping(Event event)
    {
        switch(event)
        {
            case Event::Land:
                transitionTo(State::Idle);
                break;

            default:
                break;
        }
    }
    
    void transitionTo(State newState)
    {
        std::cout << "State change: "
                  << stateToString(currentState)
                  << " -> "
                  << stateToString(newState)
                  << std::endl;

        currentState = newState;
    }
    
    const char* stateToString(State state)
    {
        switch(state)
        {
            case State::Idle: return "Idle";
            case State::Walking: return "Walking";
            case State::Running: return "Running";
            case State::Jumping: return "Jumping";
        }
        return "";
    }

};

int main()
{
    PlayerFSM player;

    player.handleEvent(Event::Move);
    player.handleEvent(Event::Run);
    player.handleEvent(Event::Jump);
    player.handleEvent(Event::Land);
    player.handleEvent(Event::Stop);

    return 0;
}