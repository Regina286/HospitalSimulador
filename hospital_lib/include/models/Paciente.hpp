#pragma once
#include <string>
namespace Modelo {

    // Niveles de urgencia (1 es lo más grave)
    enum class NivelUrgencia {
        Resucitacion = 1,
        Emergencia = 2,
        Urgencia = 3,
        UrgenciaMenor = 4,
        SinUrgencia = 5
    };

    struct Paciente {
        int id;
        std::string nombre;
        NivelUrgencia urgencia;
        std::string sintoma;

        // Constructor vacío (necesario para crear arrays o listas vacías)
        Paciente() : id(0), urgencia(NivelUrgencia::SinUrgencia) {}

        // Constructor con datos
        Paciente(int id, std::string nom, NivelUrgencia urg, std::string sin)
            : id(id), nombre(nom), urgencia(urg), sintoma(sin) {
        }

        // --- TRUCO IMPORTANTE ---
        // Esto le enseña a la computadora cómo comparar dos pacientes.
        // Sirve para que la Cola de Prioridad se ordene sola.
        bool operator<(const Paciente& otro) const {
            // Ojo: Si mi urgencia es MAYOR número (ej: 5), tengo MENOR prioridad que un 1.
            return (int)this->urgencia > (int)otro.urgencia;
        }

        bool operator>(const Paciente& otro) const {
            return (int)this->urgencia < (int)otro.urgencia;
        }
    };
}