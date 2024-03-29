// This module implements the QsciLexerTeX class.
//
// Copyright (c) 2007
// 	Phil Thompson <phil@river-bank.demon.co.uk>
// 
// This file is part of QScintilla.
// 
// This copy of QScintilla is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option) any
// later version.
// 
// QScintilla is supplied in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
// 
// You should have received a copy of the GNU General Public License along with
// QScintilla; see the file LICENSE.  If not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.


#include "Qsci/qscilexertex.h"

#include <qcolor.h>
#include <qfont.h>


// The ctor.
QsciLexerTeX::QsciLexerTeX(QObject *parent)
    : QsciLexer(parent)
{
}


// The dtor.
QsciLexerTeX::~QsciLexerTeX()
{
}


// Returns the language name.
const char *QsciLexerTeX::language() const
{
    return "TeX";
}


// Returns the lexer name.
const char *QsciLexerTeX::lexer() const
{
    return "tex";
}


// Return the string of characters that comprise a word.
const char *QsciLexerTeX::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\\@";
}


// Returns the foreground colour of the text for a style.
QColor QsciLexerTeX::defaultColor(int style) const
{
    switch (style)
    {
    case Default:
        return QColor(0x3f,0x3f,0x3f);

    case Special:
        return QColor(0x00,0x7f,0x7f);

    case Group:
        return QColor(0x7f,0x00,0x00);

    case Symbol:
        return QColor(0x7f,0x7f,0x00);

    case Command:
        return QColor(0x00,0x7f,0x00);
    }

    return QsciLexer::defaultColor(style);
}


// Returns the set of keywords.
const char *QsciLexerTeX::keywords(int set) const
{
    if (set == 1)
        return
            "above abovedisplayshortskip abovedisplayskip "
            "abovewithdelims accent adjdemerits advance "
            "afterassignment aftergroup atop atopwithdelims "
            "badness baselineskip batchmode begingroup "
            "belowdisplayshortskip belowdisplayskip binoppenalty "
            "botmark box boxmaxdepth brokenpenalty catcode char "
            "chardef cleaders closein closeout clubpenalty copy "
            "count countdef cr crcr csname day deadcycles def "
            "defaulthyphenchar defaultskewchar delcode delimiter "
            "delimiterfactor delimeters delimitershortfall "
            "delimeters dimen dimendef discretionary "
            "displayindent displaylimits displaystyle "
            "displaywidowpenalty displaywidth divide "
            "doublehyphendemerits dp dump edef else "
            "emergencystretch end endcsname endgroup endinput "
            "endlinechar eqno errhelp errmessage "
            "errorcontextlines errorstopmode escapechar everycr "
            "everydisplay everyhbox everyjob everymath everypar "
            "everyvbox exhyphenpenalty expandafter fam fi "
            "finalhyphendemerits firstmark floatingpenalty font "
            "fontdimen fontname futurelet gdef global group "
            "globaldefs halign hangafter hangindent hbadness "
            "hbox hfil horizontal hfill horizontal hfilneg hfuzz "
            "hoffset holdinginserts hrule hsize hskip hss "
            "horizontal ht hyphenation hyphenchar hyphenpenalty "
            "hyphen if ifcase ifcat ifdim ifeof iffalse ifhbox "
            "ifhmode ifinner ifmmode ifnum ifodd iftrue ifvbox "
            "ifvmode ifvoid ifx ignorespaces immediate indent "
            "input inputlineno input insert insertpenalties "
            "interlinepenalty jobname kern language lastbox "
            "lastkern lastpenalty lastskip lccode leaders left "
            "lefthyphenmin leftskip leqno let limits linepenalty "
            "line lineskip lineskiplimit long looseness lower "
            "lowercase mag mark mathaccent mathbin mathchar "
            "mathchardef mathchoice mathclose mathcode mathinner "
            "mathop mathopen mathord mathpunct mathrel "
            "mathsurround maxdeadcycles maxdepth meaning "
            "medmuskip message mkern month moveleft moveright "
            "mskip multiply muskip muskipdef newlinechar noalign "
            "noboundary noexpand noindent nolimits nonscript "
            "scriptscript nonstopmode nulldelimiterspace "
            "nullfont number omit openin openout or outer output "
            "outputpenalty over overfullrule overline "
            "overwithdelims pagedepth pagefilllstretch "
            "pagefillstretch pagefilstretch pagegoal pageshrink "
            "pagestretch pagetotal par parfillskip parindent "
            "parshape parskip patterns pausing penalty "
            "postdisplaypenalty predisplaypenalty predisplaysize "
            "pretolerance prevdepth prevgraf radical raise read "
            "relax relpenalty right righthyphenmin rightskip "
            "romannumeral scriptfont scriptscriptfont "
            "scriptscriptstyle scriptspace scriptstyle "
            "scrollmode setbox setlanguage sfcode shipout show "
            "showbox showboxbreadth showboxdepth showlists "
            "showthe skewchar skip skipdef spacefactor spaceskip "
            "span special splitbotmark splitfirstmark "
            "splitmaxdepth splittopskip string tabskip textfont "
            "textstyle the thickmuskip thinmuskip time toks "
            "toksdef tolerance topmark topskip tracingcommands "
            "tracinglostchars tracingmacros tracingonline "
            "tracingoutput tracingpages tracingparagraphs "
            "tracingrestores tracingstats uccode uchyph "
            "underline unhbox unhcopy unkern unpenalty unskip "
            "unvbox unvcopy uppercase vadjust valign vbadness "
            "vbox vcenter vfil vfill vfilneg vfuzz voffset vrule "
            "vsize vskip vsplit vss vtop wd widowpenalty write "
            "xdef xleaders xspaceskip year "
            "TeX bgroup egroup endgraf space empty null newcount "
            "newdimen newskip newmuskip newbox newtoks newhelp "
            "newread newwrite newfam newlanguage newinsert newif "
            "maxdimen magstephalf magstep frenchspacing "
            "nonfrenchspacing normalbaselines obeylines "
            "obeyspaces raggedr ight ttraggedright thinspace "
            "negthinspace enspace enskip quad qquad smallskip "
            "medskip bigskip removelastskip topglue vglue hglue "
            "break nobreak allowbreak filbreak goodbreak "
            "smallbreak medbreak bigbreak line leftline "
            "rightline centerline rlap llap underbar strutbox "
            "strut cases matrix pmatrix bordermatrix eqalign "
            "displaylines eqalignno leqalignno pageno folio "
            "tracingall showhyphens fmtname fmtversion hphantom "
            "vphantom phantom smash";

    return 0;
}


// Returns the user name of a style.
QString QsciLexerTeX::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");

    case Special:
        return tr("Special");

    case Group:
        return tr("Group");

    case Symbol:
        return tr("Symbol");

    case Command:
        return tr("Command");

    case Text:
        return tr("Text");
    }

    return QString();
}
