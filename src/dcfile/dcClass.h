// Filename: dcClass.h
// Created by:  drose (05Oct00)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#ifndef DCCLASS_H
#define DCCLASS_H

#include "dcbase.h"
#include "dcField.h"
#include "dcDeclaration.h"
#include "dcPython.h"

static const bool dc_multiple_inheritance = true;
static const bool dc_virtual_inheritance = true;
static const bool dc_sort_inheritance_by_file = true;

class HashGenerator;
class DCParameter;

////////////////////////////////////////////////////////////////////
//       Class : DCClass
// Description : Defines a particular DistributedClass as read from an
//               input .dc file.
////////////////////////////////////////////////////////////////////
class EXPCL_DIRECT DCClass : public DCDeclaration
{
	public:
		DCClass(DCFile *dc_file, const string &name,
		        bool is_struct, bool bogus_class);
		~DCClass();

	PUBLISHED:
		virtual DCClass *as_class();
		virtual const DCClass *as_class() const;

		INLINE DCFile *get_dc_file() const;

		INLINE const string &get_name() const;
		INLINE int get_number() const;

		int get_num_parents() const;
		DCClass *get_parent(int n) const;

		bool has_constructor() const;
		DCField *get_constructor() const;

		int get_num_fields() const;
		DCField *get_field(int n) const;

		DCField *get_field_by_name(const string &name) const;
		DCField *get_field_by_index(int index_number) const;

		int get_num_inherited_fields() const;
		DCField *get_inherited_field(int n) const;

		INLINE bool is_struct() const;
		INLINE bool is_bogus_class() const;
		bool inherits_from_bogus_class() const;

		INLINE void start_generate();
		INLINE void stop_generate();

		virtual void output(ostream &out) const;

	public:
		virtual void output(ostream &out, bool brief) const;
		virtual void write(ostream &out, bool brief, int indent_level) const;
		void output_instance(ostream &out, bool brief, const string &prename,
		                     const string &name, const string &postname) const;
		void generate_hash(HashGenerator &hashgen) const;
		void clear_inherited_fields();
		void rebuild_inherited_fields();

		bool add_field(DCField *field);
		void add_parent(DCClass *parent);
		void set_number(int number);

	private:
		void shadow_inherited_field(const string &name);

		DCFile *_dc_file;

		string _name;
		bool _is_struct;
		bool _bogus_class;
		int _number;

		typedef pvector<DCClass *> Parents;
		Parents _parents;

		DCField *_constructor;

		typedef pvector<DCField *> Fields;
		Fields _fields, _inherited_fields;

		typedef pmap<string, DCField *> FieldsByName;
		FieldsByName _fields_by_name;

		typedef pmap<int, DCField *> FieldsByIndex;
		FieldsByIndex _fields_by_index;

		friend class DCField;
};

#include "dcClass.I"

#endif
