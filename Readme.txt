What is this ?
Creating a simple C++ class hierarchy for processing the gcc tree information.
Plan is to use this as a clean interface to introspection data, be it from the gcc plugin, or dump files or from debug information or other sources.

== Foo.cpp== 
The foo function is a just an example function

== Simple.cpp== 
This contains some definitions to hold the tree definitions and functions to receive the tree dump format. 

=ideas=

1. be able to invoke the compiler any time to process snippets and dump a tree of them.
   this is also good for debugging compiler errors or template nightmares
   the treedump is not always complete, we might have to patch the compiler to include more information in the future.
2. Be able to read in the tree file into a clean C++ structure. This will allow users to easily store and load files.
3. create bridge into other formats, like the gnome introspection repository.
4. be able to generate dump files from a given memory representation of the new format
5. create an xml or even rdf representation
6. dotty graphviz format as well.
7. Be able to extract from the dwarf data
8. extract even objdump basic information (.text headers). this from runtime or compile time.
9. create a gcc plugin that can extract these trees
10. create a gcc front end to parse and process code in these trees
11. be able to express a Domain Specific Language DSL in the trees, and then process it.
11.1. be able to define analogous like objects and classes from languages defined in c like java, php, perl and python. 
we want to be able to create recognizers for these objects or idioms in memory. There are many different representations. 
What about DOM objects in perl containing class infomation? We dont want to automatically recognize this, but allow users to create recognizers of graph structures, either in static or dynamic structures defined in c.
