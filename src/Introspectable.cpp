/*
 * Copyright (C) 2010 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alex Launi <alex.launi@canonical.com>
 */

#include "Introspectable.h"

GVariant*
Introspectable::introspect ()
{
	GVariant		*result;
	GVariant        *childResults;
	GVariantBuilder *builder;

	builder = g_variant_builder_new (G_VARIANT_TYPE ("a{sv}"));
	for (std::list<Introspectable*>::iterator it = _children.begin (); it != _children.end (); it++) {
		g_variant_builder_add (builder, "{sv}", (*it)->getName (), (*it)->introspect ());
	}	
	addProperties (builder);

	childResults = g_variant_new ("(a{sv})", builder);
	g_variant_builder_unref (builder);

	if (_children.size () > 0) {
		builder = g_variant_builder_new (G_VARIANT_TYPE ("a{sv}"));
		g_variant_builder_add (builder, "{sv}", getName (), childResults);
		result = g_variant_new ("(a{sv})", builder);
		g_variant_builder_unref (builder);

		return result;
	}
	
	return childResults;
}

void
Introspectable::addChild (Introspectable *child)
{
	_children.push_back (child);
}

void 
Introspectable::removeChild (Introspectable *child)
{
	_children.remove (child);
}