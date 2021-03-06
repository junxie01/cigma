#ifndef __VTK_LIST_H__
#define __VTK_LIST_H__


typedef enum {
    VTK_FILE_NONE,
    VTK_FILE_POLYDATA,
    VTK_FILE_STRUCTURED_POINTS,
    VTK_FILE_STRUCTURED_GRID,
    VTK_FILE_UNSTRUCTURED_GRID,
    VTK_FILE_RECTILINEAR_GRID
} VtkFileType;

//VtkFileType getFileType(vtkDataSetReader *reader);
const char *getFileTypeName(VtkFileType fileType);

void list_vtk(const char *filename);
void list_vts(const char *filename);


#endif
