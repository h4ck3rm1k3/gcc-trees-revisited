#pragma once 
namespace Rel //ationships
{
  template <class T> class Pointer {};
  template <class T> class Reference {};
  template <class T> class TemplateVersion {};

  class InverseOf {};
  template <class T> class TInverseOf {
    TemplateVersion<InverseOf> derived_from;// the template version of InverseOf
  };

  class Contains {};


  template <class T> class TContains {
    TemplateVersion<Contains> derived_from;// the template version of contains
  }; 

  class IsContained {
    TInverseOf<Contains> inverse;
  };

  template <class T> class TIsContained {
    TemplateVersion<IsContained> derived_from;// the template version of IsContained
  }; 

};
///
