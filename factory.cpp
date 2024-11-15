// Abstract Factory and Singleton program for Word Generation
// Creation based off of Creational Pattern Week 3 & 4 Slides
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Abstract Factory Button Class
class Button {
public: 
	virtual void print() {};
};

// Concrete Button Classes
class Button00 : public Button {
public:
	void print() {
		cout << "Button Word00" << endl;
	}
};

class Button10 : public Button {
public:
	void print() {
		cout << "Button Word10" << endl;
	}
};

class Button21 : public Button {
public:
	void print() {
		cout << "Button Word21" << endl;
	}
};

class Button90 : public Button {
public:
	void print() {
		cout << "Button Word90" << endl;
	}
};

// Abstract Factory Textbox Class
class Textbox {
public:
	virtual void print() {};
};

class Textbox00 : public Textbox {
public:
	void print() {
		cout << "Textbox Word00" << endl;
	}
};

// Concrete Textbox Classes
class Textbox10 : public Textbox {
public:
	void print() {
		cout << "Textbox Word10" << endl;
	}
};

class Textbox21 : public Textbox {
public:
	void print() {
		cout << "Textbox Word21" << endl;
	}
};

class Textbox90 : public Textbox {
public:
	void print() {
		cout << "Textbox Word90" << endl;
	}
};




// Abstract Factory Panel Class
class Panel {
public: 
	virtual void print() {};
};

// Concrete Panel Classes
class Panel00 : public Panel {
public:
	void print() {
		cout << "Panel Word00" << endl;
	}
};

class Panel10 : public Panel {
public:
	void print() {
		cout << "Panel Word10" << endl;
	}
};

class Panel21 : public Panel {
public:
	void print() {
		cout << "Panel Word21" << endl;
	}
};

class Panel90 : public Panel {
public:
	void print() {
		cout << "Panel Word90" << endl;
	}
};


// Abstract Factory Word Class to create Family of Objects
class Word {
public:
	virtual Button* createButton() = 0;
	virtual Textbox* createTextbox() = 0;
	virtual Panel* createPanel() = 0;
};


// Concrete Word00 Class
class Word00 : public Word {
	// Variable to track the number of instances
	static int instanceCounter;

public: 
	// Constructor that increments our instance counter when this generation is created.
	Word00() {
		instanceCounter++;
	}

	// Function to return value based on number of instances for specific print out.
	static Word00* getInstance() {
		// Check to Make sure more than 2 instances have not be created (Singleton)
		if (instanceCounter < 2) {
			return new Word00();
		}
		else {
			return nullptr;
		}
	}
	// Create GUI components for this generation
	Button* createButton() {
		return new Button00();
	}

	Textbox* createTextbox() {
		return new Textbox00();
	}

	Panel* createPanel() {
		return new Panel00();
	}

};


// Concrete Word10 Class
class Word10 : public Word {
	// Variable to track the number of instances
	static int instanceCounter;

public:

	// Constructor that increments our instance counter when this generation is created.
	Word10() {
		instanceCounter++;
	}

	// Function to return value based on number of instances for specific print out.
	static Word10* getInstance() {
		// Check to Make sure more than 2 instances have not be created (Singleton)
		if (instanceCounter < 2) {
			return new Word10();
		}
		else {
			return nullptr;
		}
	}

	// Create GUI components for this generation
	Button* createButton() {
		return new Button10();
	}

	Textbox* createTextbox() {
		return new Textbox10();
	}

	Panel* createPanel() {
		return new Panel10();
	}

};


// Concrete Word21 Class
class Word21 : public Word {
	// Variable to track the number of instances
	static int instanceCounter;

public:

	// Constructor that increments our instance counter when this generation is created.
	Word21() {
		instanceCounter++;
	}

	// Function to return value based on number of instances for specific print out.
	static Word21* getInstance() {
		// Check to Make sure more than 2 instances have not be created (Singleton)
		if (instanceCounter < 2) {
			return new Word21();
		}
		else {
			return nullptr;
		}
	}

	// Create GUI components for this generation
	Button* createButton() {
		return new Button21();
	}

	Textbox* createTextbox() {
		return new Textbox21();
	}

	Panel* createPanel() {
		return new Panel21();
	}

};

// Concrete Word90 Class
class Word90 : public Word {
	// Variable to track the number of instances
	static int instanceCounter;

public:

	// Constructor that increments our instance counter when this generation is created.
	Word90() {
		instanceCounter++;
	}

	// Function to return value based on number of instances for specific print out.
	static Word90* getInstance() {
		// Check to Make sure more than 2 instances have not be created (Singleton)
		if (instanceCounter < 2) {
			return new Word90();
		}
		else {
			return nullptr;
		}
	}

	// Create GUI components for this generation
	Button* createButton() {
		return new Button90();
	}

	Textbox* createTextbox() {
		return new Textbox90();
	}

	Panel* createPanel() {
		return new Panel90();
	}

};


// ApControl, modeled after the Abstract Factory example from Lecture
// Another name for this could be Client class.
class ApControl {
	// Create the GUI Components
	Button* button;
	Textbox* textbox;
	Panel* panel;

public:
	// Call the Abstract Factory Word Class to create our components.
	ApControl(Word* factory) {
		button = factory->createButton();
		textbox = factory->createTextbox();
		panel = factory->createPanel();
	}

	// Print the information to screen 
	void printToScreen() {
		button->print();
		textbox->print();
		panel->print();
	}


};


