/* 

                          Firewall Builder

                 Copyright (C) 2008 NetCitadel, LLC

  Author:  alek@codeminders.com

  $Id$

  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#ifndef PROJECTPANEL_H
#define PROJECTPANEL_H

#include "ObjectEditor.h"
#include "ui_projectpanel_q.h"

namespace libfwbuilder {
    class FWObjectDatabase;
    class Firewall;
    class PolicyRule;
    class RuleSet;
    class Rule;
    class RuleElement;
    class FWObject;
    class FWReference;
};

class QWidget;
class QMdiSubWindow;
class QTextEdit;
class ObjectTreeView;
class ObjectManipulator;
class findDialog;
class FWWindow;
class RuleSetView;
class RCS;

class FindObjectWidget;
class FindWhereUsedWidget;
class listOfLibraries;
class FWBTree;

#define DEFAULT_H_SPLITTER_POSITION 250
#define DEFAULT_V_SPLITTER_POSITION 450


class ProjectPanel: public QWidget {
    Q_OBJECT

    FWWindow                               *mainW;
    RCS                                    *rcs;
    listOfLibraries                        *addOnLibs;
    FWBTree                                *objectTreeFormat;
    bool                                    systemFile;
    bool                                    safeMode;
    bool                                    editingStandardLib;
    bool                                    editingTemplateLib;
    bool                                    ruleSetRedrawPending;
    bool                                    closing ;
    bool                                    ready;
    QString                                 startupFileName;
    
    libfwbuilder::FWObjectDatabase         *objdb;
    QWidget                                *editorOwner;
    
    //QTextEdit                              *oi;
    //ObjectManipulator                      *om; 
    ObjectEditor                           *oe;
    findDialog                             *fd;
    libfwbuilder::FWObject                 *shownInInfo;
        
    QTimer                                 *autosaveTimer;
    std::map<libfwbuilder::FWObject*, RuleSetView*> ruleSetViews;
    int                                     ruleSetTabIndex;
    
    libfwbuilder::FWObject                 *visibleFirewall;
    libfwbuilder::RuleSet                  *visibleRuleSet ;
    std::vector<libfwbuilder::FWObject*>    firewalls;

    int                                     lastFirewallIdx;
    bool                                    changingTabs;
    QString                                 noFirewalls;
    bool                                    enableAvtoSaveState;
    
public:

    QMdiSubWindow *mdiWindow;
    Ui::ProjectPanel_q *m_panel;
    FindObjectWidget *findObjectWidget;
    FindWhereUsedWidget *findWhereUsedWidget;
    QSet<QString> copySet;

    
    void readyStatus(bool f) { ready=f; }

    libfwbuilder::RuleSet* getCurrentRuleSet () {return visibleRuleSet;};
    RuleSetView* getCurrentRuleSetView() ;

    ProjectPanel* clone(ProjectPanel * cln);

    void openRuleSet(libfwbuilder::FWObject *obj);
    void closeRuleSet(libfwbuilder::FWObject *obj)
    { if ((libfwbuilder::FWObject*)(visibleRuleSet)==obj) visibleRuleSet=NULL;};
    
    FWBTree * getFWTree () {return objectTreeFormat;};
    bool isClosing (){return closing;};


    ProjectPanel(QWidget *parent);
    ~ProjectPanel();


    void initMain(FWWindow *main);
    void loadObjects();
    void loadObjects(libfwbuilder::FWObjectDatabase *db);
    void clearObjects();
    libfwbuilder::FWObjectDatabase* db() { return objdb; };
    bool hasObject(libfwbuilder::FWObject* obj)
    { return objdb->findInIndex(obj->getId()); };

    libfwbuilder::RuleElement* getRE(libfwbuilder::Rule* r, int col );

    //wrapers for some ObjectManipulator functions
    libfwbuilder::FWObject* getOpened();
    
    libfwbuilder::FWObject*  getCurrentLib();

    libfwbuilder::FWObject* createObject(const QString &objType,
                                         const QString &objName,
                                         libfwbuilder::FWObject *copyFrom=NULL);

    libfwbuilder::FWObject* createObject(libfwbuilder::FWObject *parent,
                                         const QString &objType,
                                         const QString &objName,
                                         libfwbuilder::FWObject *copyFrom=NULL);


    FWWindow* getWindow (){ return mainW;}     
    void moveObject(libfwbuilder::FWObject *target,
                    libfwbuilder::FWObject *obj);

    void moveObject(const QString &targetLibName,
                    libfwbuilder::FWObject *obj);

    void autorename(libfwbuilder::FWObject *obj,
                    const std::string &objtype,
                    const std::string &namesuffix);

    void updateLibColor(libfwbuilder::FWObject *lib);
    void updateLibName(libfwbuilder::FWObject *lib);

    void updateObjName(libfwbuilder::FWObject *obj,
                       const QString &oldName,
                       bool  askForAutorename=true);
    void updateObjName(libfwbuilder::FWObject *obj,
                       const QString &oldName,
                       const QString &oldLabel,
                       bool  askForAutorename=true);

    void updateLastModifiedTimestampForOneFirewall(libfwbuilder::FWObject *o);
    void updateLastModifiedTimestampForAllFirewalls(libfwbuilder::FWObject *o);   
    void updateLastInstalledTimestamp(libfwbuilder::FWObject *o);
    void updateLastCompiledTimestamp(libfwbuilder::FWObject *o);
       
    void loadDataFromFw(libfwbuilder::Firewall *fw);
    
    libfwbuilder::FWObject* pasteTo(libfwbuilder::FWObject *target,
                                    libfwbuilder::FWObject *obj);
    void delObj(libfwbuilder::FWObject *obj,bool openobj=true);
    ObjectTreeView* getCurrentObjectTree();
    void openObject(QTreeWidgetItem *otvi);
    void openObject(libfwbuilder::FWObject *obj);
    bool editObject(libfwbuilder::FWObject *obj);
    void findAllFirewalls (std::list<libfwbuilder::Firewall *> &fws);

    libfwbuilder::FWObject* duplicateObject(libfwbuilder::FWObject *target,
                                            libfwbuilder::FWObject *obj,
                                            const QString &name = QString::null,
                                            bool  askForAutorename=true);
    void showDeletedObjects(bool f);
    void select();
    void unselect();

    void copyObj();
    bool isManipulatorSelected();
    void cutObj();
    void pasteObj();
    
    void deleteObj();
    libfwbuilder::FWObject* getSelectedObject();
    void reopenCurrentItemParent();
    
    void setManipulatorFocus();
    void clearManipulatorFocus();
    
    //wrapers for some Object Editor functions
    bool isEditorVisible();
    bool isEditorModified();
    
    void showEditor();
    void hideEditor();
    void closeEditor();
    
    void openEditor(libfwbuilder::FWObject *o);
    void openOptEditor(libfwbuilder::FWObject *, ObjectEditor::OptType t);
    void blankEditor();
    
    libfwbuilder::FWObject* getOpenedEditor();
    ObjectEditor::OptType getOpenedOptEditor();
    
    void selectObjectInEditor(libfwbuilder::FWObject *o);

    void actionChangedEditor(libfwbuilder::FWObject *o);
    bool validateAndSaveEditor();
    //find dialog functions wrapers
    void setFDObject(libfwbuilder::FWObject *o);
    
    void info(libfwbuilder::FWObject *o, bool forced = false);    
    void resetFD();
    
    void clearFirewallTabs();
    void ensureObjectVisibleInRules(libfwbuilder::FWReference *obj);
    void ensureRuleIsVisible(libfwbuilder::Rule *rule, int col=0);
    
    libfwbuilder::FWObject* getVisibleFirewall() { return visibleFirewall; }
    RuleSetView* getRuleSetViews(libfwbuilder::FWObject *o) 
    {return ruleSetViews[o];};

    void updateRuleSetViewSelection();
    void updateRuleSetView();
    void updateRuleOptions();
    void updateTreeViewItemOrder();
    int  findFirewallInList(libfwbuilder::FWObject *f);
    void updateFirewallName();
    void scheduleRuleSetRedraw();
    void selectRules();
    void unselectRules();
    void editCopy();
    void editCut();
    void editDelete();
    void editPaste();
    
    bool saveIfModified();
    QString getDestDir(const QString &fname);
    QString chooseNewFileName(const QString &fname, const QString &title);
    void setFileName(const QString &fname);
    void restoreDepends(libfwbuilder::FWObject *obj_old,
                        libfwbuilder::FWObject *nobj, 
                        const std::map<int,
                        libfwbuilder::FWObject *> &objByIds);

    QString getPageTitle();
    
 public slots:
    void newObject();
    void info();
    
    virtual void back();
    virtual void lockObject();
    virtual void unlockObject();
 
    virtual void insertRule();
    virtual void addRuleAfterCurrent();
    virtual void moveRule();
    virtual void moveRuleUp();
    virtual void moveRuleDown();
    virtual void removeRule(); 

    virtual void copyRule();
    virtual void cutRule();
    virtual void pasteRuleAbove();
    virtual void pasteRuleBelow();

    virtual void reopenFirewall();
    virtual void redrawRuleSets();
    virtual void changeInfoStyle();
    virtual void restoreRuleSetTab();

    virtual void fileProp();
    virtual bool fileNew();
    virtual bool fileOpen();

    virtual void fileClose();
    virtual void fileSave();
    virtual void fileSaveAs();
    virtual void fileExit();
    virtual void fileCommit();
    virtual void fileDiscard();
    virtual void fileAddToRCS();
    
    virtual void startupLoad();
    
    virtual void fileImport();
    virtual void fileCompare();
    virtual void fileExport();
    
    virtual void closeAuxiliaryPanel();
    virtual void closeEditorPanel();
    virtual void openEditorPanel();
    
    virtual void search();

    virtual void compile(std::set<libfwbuilder::Firewall * > vf);
    virtual void compile();
    virtual void install(std::set<libfwbuilder::Firewall * > vf);
    virtual void install();
     
    virtual void rollBackSelectionSameWidget();
    virtual void rollBackSelectionDifferentWidget();
    void splitterMoved ( int pos, int index );
    void stateChanged(Qt::WindowStates oldState, Qt::WindowStates newState);

    virtual void autoSave();
    
 signals:
     void restoreSelection_sign(bool same_widget);


public:
    QString getFileName();
    bool editingLibrary();
    void createRCS( const QString &filename);
    void loadFromRCS(RCS *rcs);
    void loadStandardObjects();
    bool loadFile(const QString &fileName, bool load_rcs_head);

    void save();

    void saveState();
    void loadState(bool open_objects=true);

    void loadOpenedRuleSet();
    void saveOpenedRuleSet();

    void saveLastOpenedLib();
    void loadLastOpenedLib();
    
    bool checkin(bool unlock);
    void loadLibrary(const std::string &libfpath);
    
    bool exportLibraryTest(std::list<libfwbuilder::FWObject*> &selectedLibs);
    void exportLibraryTo(QString fname,
                         std::list<libfwbuilder::FWObject*> &selectedLibs,
                         bool rof);

    void findExternalRefs(libfwbuilder::FWObject *lib,
                       libfwbuilder::FWObject *root,
                       std::list<libfwbuilder::FWReference*> &extRefs);
    
    void setSafeMode(bool f) { safeMode=f; }
    void setStartupFileName(const QString &fn);
    void setupAutoSave();
    QString getCurrentFileName();
    RCS * getRCS();
    void findObject(libfwbuilder::FWObject *);
    void findWhereUsed(libfwbuilder::FWObject *);
    QString printHeader();
    bool requestEditorOwnership(QWidget *w,
                                libfwbuilder::FWObject *o,
                                ObjectEditor::OptType   otype,
                                bool validate = true);
    void releaseEditor();
    void connectEditor(QWidget *w);
    listOfLibraries *getAddOnLibs();


    bool isSystem(libfwbuilder::FWObject *obj);
    bool isStandardId(libfwbuilder::FWObject *obj);    
    bool validateForInsertion(libfwbuilder::FWObject *target,libfwbuilder::FWObject *obj);
    bool getCopyMenuState(const QString &objPath);
    bool getCutMenuState(const QString &objPath);
    bool getPasteMenuState(const QString &objPath);
    bool getDeleteMenuState(libfwbuilder::FWObject *obj);
    libfwbuilder::FWObject* createNewLibrary(libfwbuilder::FWObjectDatabase *db);


protected:
    int oldState ;
    virtual void showEvent( QShowEvent *ev);
    virtual void hideEvent( QHideEvent *ev);
    virtual void closeEvent( QCloseEvent * );
    virtual void resizeEvent ( QResizeEvent * event );

    void setMainSplitterPosition(int w1, int w2);
    void setObjInfoSplitterPosition(int w1, int w2);
};

#endif
