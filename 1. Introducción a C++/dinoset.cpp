#include <iostream>

using namespace std;

const int total_dinos = 8;

enum class DinoId {
    velocirraptor,      // 0
    estegosaurio,       // 1
    tiranosaurio,       // 2
    procompsagnatus,    // 3
    triceratops,        // 4
    paquicefalosaurio,  // 5
    parasaurolofus,     // 6
    pteranodon          // 7
};

string dino_names[] = {
    "velocirraptor",      // 0
    "estegosaurio",       // 1
    "tiranosaurio",       // 2
    "procompsagnatus",    // 3
    "triceratops",        // 4
    "paquicefalosaurio",  // 5
    "parasaurolofus",     // 6
    "pteranodon"          // 7
};

class DinoSet {

public:

    bool contains(DinoId id) const
    {
        int indice = static_cast<int>(id);
        return _dino[indice];
    }

    void add(DinoId id)
    {
        int indice = static_cast<int>(id);
        _dino[indice] = true;
    }

    DinoSet operator+(const DinoSet& other) const
    {
        DinoSet result;

        for (int i = 0; i < total_dinos; ++i) {
            DinoId id = static_cast<DinoId>(i);
            if (contains(id) || other.contains(id)) {
                result.add(id);
            }
        }

        return result;
    }

    string to_string() const
    {
        string resultado = "{";
        bool primero = true;
        for (int i = 0; i < total_dinos; ++i) {
            if (_dino[i]) {
                if (primero) {
                    primero = false;
                } else {
                    resultado += ", ";
                }
                resultado += dino_names[i];
            }
        }
        return resultado + "}";
    }

private:
    bool _dino[total_dinos] {};

};

ostream& operator<<(ostream& os, const DinoSet& dino)
{
    return os << dino.to_string();
}

int main()
{
    DinoSet a;
    a.add(DinoId::velocirraptor);
    a.add(DinoId::parasaurolofus);
    DinoSet b;
    b.add(DinoId::estegosaurio);
    b.add(DinoId::velocirraptor);
    DinoSet c = a + b;
    DinoSet d;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}