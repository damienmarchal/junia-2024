#include <string>

class Environment;

class EnvironmentLogger {
public:
    EnvironmentLogger(Environment* environment, const std::string& filename);
    
    void begin();

    void log_state();

    void end();
    

private:
    Environment* environment_;
    std::string filename_;
    int iteration_ = 0;  // Vous pouvez ajuster cette valeur en fonction de la simulation
};
