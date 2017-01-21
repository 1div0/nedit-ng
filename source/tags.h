/*******************************************************************************
*                                                                              *
* tags.h -- Nirvana Editor Tags Header File                                    *
*                                                                              *
* Copyright 2002 The NEdit Developers                                          *
*                                                                              *
* This is free software; you can redistribute it and/or modify it under the    *
* terms of the GNU General Public License as published by the Free Software    *
* Foundation; either version 2 of the License, or (at your option) any later   *
* version. In addition, you may distribute versions of this program linked to  *
* Motif or Open Motif. See README for details.                                 *
*                                                                              *
* This software is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for    *
* more details.                                                                *
*                                                                              *
* You should have received a copy of the GNU General Public License along with *
* software; if not, write to the Free Software Foundation, Inc., 59 Temple     *
* Place, Suite 330, Boston, MA  02111-1307 USA                                 *
*                                                                              *
* Nirvana Text Editor                                                          *
* July 31, 2001                                                                *
*                                                                              *
*******************************************************************************/

#ifndef TAGS_H_
#define TAGS_H_

#include <X11/Intrinsic.h>
#include <ctime>
#include <string>

class Document;

struct tagFile {
	tagFile     *next;
	std::string filename;
	time_t      date;
	bool        loaded;
	short       index;
	short       refcount; // Only tips files are refcounted, not tags files
};

extern tagFile *TagsFileList; // list of loaded tags files
extern tagFile *TipsFileList; // list of loaded calltips tag files
extern int searchMode;

// file_type and search_type arguments are to select between tips and tags,
// and should be one of TAG or TIP.  TIP_FROM_TAG is for ShowTipString.
enum Mode {
	TAG, 
	TIP_FROM_TAG, 
	TIP
};

int AddRelTagsFile(const char *tagSpec, const char *windowPath, int file_type);
// tagSpec is a colon-delimited list of filenames 
int AddTagsFile(const char *tagSpec, int file_type);
int DeleteTagsFile(const char *tagSpec, int file_type, bool force_unload);

int AddTagsFileEx(const QString &tagSpec, int file_type);
int DeleteTagsFileEx(const QString &tagSpec, int file_type, Boolean force_unload);

int LookupTag(const char *name, const char **file, int *lang, const char **searchString, int *pos, const char **path, int search_type);

// Routines for handling tags or tips from the current selection
void FindDefinition(Document *window, Time time, const char *arg);
void FindDefCalltip(Document *window, Time time, const char *arg);

//  Display (possibly finding first) a calltip.  Search type can only be TIP or TIP_FROM_TAG here.
int ShowTipString(Document *window, char *text, Boolean anchored, int pos, Boolean lookup, int search_type, int hAlign, int vAlign, int alignMode);

void editTaggedLocation(Widget parent, int i);
void showMatchingCalltip(Widget parent, int i);

#endif
