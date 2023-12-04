#include <iostream>
#include <vector>
#include <string>
#include <memory>


class Player {
public:
    Player(const std::string& name, int playerID)
        : name(name), playerID(playerID) {}

    // Pure virtual methods
    virtual std::string getPlayerPosition() const = 0;
    virtual void play() const = 0;
    virtual std::string toString() const = 0;

    // Concrete methods
    std::string getName() const { return name; }
    int getPlayerID() const { return playerID; }

protected:
    std::string name;
    int playerID;
};

// Subclasses
class QuarterBack : public Player {
public:
    QuarterBack(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Quarterback"; }
    virtual void play() const override { std::cout << "Throws the ball.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};

class WideReceiver : public Player {
public:
    WideReceiver(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "WideReceiver"; }
    virtual void play() const override { std::cout << "Catches the ball.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class TightEnd : public Player {
public:
    TightEnd(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "TightEnd"; }
    virtual void play() const override { std::cout << "Blocks and catches the ball\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class RunningBack : public Player {
public:
    RunningBack(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Running Back"; }
    virtual void play() const override { std::cout << "Runs the ball.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class OffensiveLineMan : public Player {
public:
    OffensiveLineMan(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Offensive Lineman"; }
    virtual void play() const override { std::cout << "Protects the Quarterback.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class DefensiveBack : public Player {
public:
    DefensiveBack(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Covering the wide recievers"; }
    virtual void play() const override { std::cout << "Protects the Quarterback.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class DefensiveLineMan : public Player {
public:
    DefensiveLineMan(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Defensive Lineman"; }
    virtual void play() const override { std::cout << "stopping the ball and rushing the Quarterback.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class Linebacker : public Player {
public:
    Linebacker(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Linebacker"; }
    virtual void play() const override { std::cout << "stopping short passes.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class Returner : public Player {
public:
    Returner(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Returner"; }
    virtual void play() const override { std::cout << "returns ball from punter.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class Kicker : public Player {
public:
    Kicker(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Kicker"; }
    virtual void play() const override { std::cout << "Kicks the football.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class Holder : public Player {
public:
    Holder(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Holder"; }
    virtual void play() const override { std::cout << "Holds the ball for the kicker.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};
class Punter : public Player {
public:
    Punter(const std::string& name, int playerID)
        : Player(name, playerID) {}

    virtual std::string getPlayerPosition() const override { return "Punter"; }
    virtual void play() const override { std::cout << "Like the Kicker the Punter kicks the ball.\n"; }
    virtual std::string toString() const override {
        return getPlayerPosition() + ": " + name + " (#" + std::to_string(playerID) + ")";
    }
};



// Team class to hold players
class Team {
public:
    void addPlayer(const std::shared_ptr<Player>& player) {
        players.push_back(player);
    }

    void printTeam() const {
        std::cout << "Team Roster:\n";
        for (const auto& player : players) {
            std::cout << player->toString() << "\n";
        }
        std::cout << "Number of players on the team: " << players.size() << "\n";
    }

private:
    std::vector<std::shared_ptr<Player>> players;
};

int main() {
    Team myTeam;

    // Add players to the team
    myTeam.addPlayer(std::make_shared<QuarterBack>("Tom Brady", 12));
    myTeam.addPlayer(std::make_shared<WideReceiver>("Justin Jefferson", 18));
    myTeam.addPlayer(std::make_shared<TightEnd>("Rob Gronkowski", 87));
    myTeam.addPlayer(std::make_shared<RunningBack>("Christian McCaffrey", 22));
    myTeam.addPlayer(std::make_shared<OffensiveLineMan>("Quenton Nelson", 56));
    myTeam.addPlayer(std::make_shared<DefensiveBack>("Jalen Ramsey", 20));
    myTeam.addPlayer(std::make_shared<Punter>("Pat McAfee", 1));
    myTeam.addPlayer(std::make_shared<DefensiveLineMan>("Aaron Donald", 99));
    myTeam.addPlayer(std::make_shared<Kicker>("Adam Vinatieri", 4));
    myTeam.addPlayer(std::make_shared<Holder>("Jason Kelce", 62));
    myTeam.addPlayer(std::make_shared<Returner>("Isaiah Rodgers", 35));
    myTeam.addPlayer(std::make_shared<Linebacker>("Ray Lewis", 52));

    myTeam.printTeam();

    return 0;
}
