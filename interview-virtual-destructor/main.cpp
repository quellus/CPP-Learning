class NonVirtual {
public:
	NonVirtual() {
		string = new char[5];
	}
	
	~NonVirtual() {
		delete[] string;
	}

protected:
	char* string;
};

class Virtual {
public:
	Virtual() {
		string = new char[6];
	}

	virtual ~Virtual() {
		delete[] string;
	}
protected:
	char* string;
};

class NonVirtualChild : public NonVirtual {
public:
	NonVirtualChild() {
		secondString = new char[7];
	}

	~NonVirtualChild() {
		delete[] secondString;
	}
protected:
	char* secondString;
};

class VirtualChild : public Virtual {
public:
	VirtualChild() {
		secondString = new char[8];
	}

	~VirtualChild() {
		delete[] secondString;
	}
protected:
	char* secondString;
};

int main() {
	// Destructs safely
	NonVirtual nv;
	Virtual v;

	// Destructs safely
	NonVirtualChild nvc;
	VirtualChild vc;

	
	// Destructs safely
	NonVirtualChild nvcr;
	NonVirtual &nvr = nvcr;

	// Destructs safely
	VirtualChild vcr;
	Virtual &vr = vcr;

	// Does not destruct properly.
	// The parent destructor is never called
	NonVirtualChild* nvcp = new NonVirtualChild();
	NonVirtual *nvp = nvcp;
	delete nvp;

	// Destructs safely
	VirtualChild* vcr = new VirtualChild();
	Virtual *vr = vcr;
	delete vr;
}

