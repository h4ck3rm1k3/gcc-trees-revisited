/*
  scopes :
  translation_unit_decl ::
     function_decl foo
        parm_decl

the record type does not have a scope, 
type_decl     type   record_type
    field_decl
*/

class Scope; // forward

class Source {
  // Source File,line number and char range
};

class Scope {};
class Translation_Unit_Decl  : public Scope {};
