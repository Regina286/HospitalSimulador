#pragma once
#include <unordered_map>
#include "Paciente.hpp"
#include "Sala.hpp"
#include "Medico.hpp"

namespace Modelo {

    struct Expediente {
        Paciente paciente;
        int id_medico;
        int id_sala;

        Expediente() : id_medico(0), id_sala(0) {}
        Expediente(const Paciente& p, int med, int sala)
            : paciente(p), id_medico(med), id_sala(sala) {
        }
    };

    class TablaHashExpedientes {
    private:
        std::unordered_map<int, Expediente> tabla;

    public:
        // Insertar expediente completo
        void insertar(const Expediente& exp) {
            tabla[exp.paciente.id] = exp;
        }

        // Buscar por ID
        Expediente* buscar(int id) {
            auto it = tabla.find(id);
            if (it != tabla.end()) return &it->second;
            return nullptr;
        }

        // Eliminar por ID
        void eliminar(int id) {
            tabla.erase(id);
        }

        // Verificar existencia
        bool existe(int id) const {
            return tabla.find(id) != tabla.end();
        }
    };

}

