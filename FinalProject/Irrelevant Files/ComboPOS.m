function varargout = ComboPOS(varargin)
% COMBOPOS MATLAB code for ComboPOS.fig
%      COMBOPOS, by itself, creates a new COMBOPOS or raises the existing
%      singleton*.
%
%      H = COMBOPOS returns the handle to a new COMBOPOS or the handle to
%      the existing singleton*.
%
%      COMBOPOS('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in COMBOPOS.M with the given input arguments.
%
%      COMBOPOS('Property','Value',...) creates a new COMBOPOS or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ComboPOS_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ComboPOS_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ComboPOS

% Last Modified by GUIDE v2.5 25-Apr-2018 20:23:12

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ComboPOS_OpeningFcn, ...
                   'gui_OutputFcn',  @ComboPOS_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ComboPOS is made visible.
function ComboPOS_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ComboPOS (see VARARGIN)

% Choose default command line output for ComboPOS
handles.output = hObject;

FileID = fopen('Price List.csv' , 'r' );
Contents = textscan( FileID, '%d%d' , 'Delimiter' , ',' );
fclose( FileID );

CurrentTotal = 0;
PriceInfo = {};
for RowIndex = 1 : 1 : length(Contents {1} ) % rows/questions
    PriceInfo{ RowIndex , 1 } = Contents{ 1 } { RowIndex}; % Food
    PriceInfo{ RowIndex , 2 } = Contents{ 2 } { RowIndex}; % Type
end

% UIWAIT makes ComboPOS wait for user response (see UIRESUME)
% uiwait(handles.figure1);
handles.PriceInfo = PriceInfo; 
handles.CurrentTotal = CurrentTotal;

% Update handles structure
guidata(hObject, handles);


% --- Outputs from this function are returned to the command line.
function varargout = ComboPOS_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;





% --- Executes on button press in HomePushButton.
function HomePushButton_Callback(hObject, eventdata, handles)
% hObject    handle to HomePushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
HomeScreenPOS
close(ComboPOS)


% --- Executes on button press in TenderPushButton.
function TenderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to TenderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
TenderPOS
close(ComboPOS)

% --- Executes on button press in Combo1PushButton.
function Combo1PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo1PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Combo1 = 1;
FileID = fopen('Price List.csv' , 'r' );
Contents = textscan( FileID, '%s%s' , 'Delimiter' , ',' );
fclose( FileID );

CurrentTotal = handles.CurrentTotal;


if Combo1 == 1
      handles.CurrentTotal = handles.CurrentTotal + str2num(Contents{1,2}{8,1} );
end
CurrentTotal = handles.CurrentTotal
set(handles.CurrentTotalEditBox, 'string' , handles.CurrentTotal)



% --- Executes on button press in Combo2PushButton.
function Combo2PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo2PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Combo2 = 1;
FileID = fopen('Price List.csv' , 'r' );
Contents = textscan( FileID, '%s%s' , 'Delimiter' , ',' );
fclose( FileID );

CurrentTotal = handles.CurrentTotal;


if Combo2 == 1
      handles.CurrentTotal = handles.CurrentTotal + str2num(Contents{1,2}{9,1} );
end
CurrentTotal = handles.CurrentTotal
set(handles.CurrentTotalEditBox, 'string' , handles.CurrentTotal)


% --- Executes on button press in Combo3PushButton.
function Combo3PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo3PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Combo3 = 1;
FileID = fopen('Price List.csv' , 'r' );
Contents = textscan( FileID, '%s%s' , 'Delimiter' , ',' );
fclose( FileID );

CurrentTotal = handles.CurrentTotal;


if Combo3 == 1
      handles.CurrentTotal = handles.CurrentTotal + str2num(Contents{1,2}{10,1} );
end
CurrentTotal = handles.CurrentTotal
set(handles.CurrentTotalEditBox, 'string' , handles.CurrentTotal)



% --- Executes on button press in Combo4PushButton.
function Combo4PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo4PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Combo4 = 1;
FileID = fopen('Price List.csv' , 'r' );
Contents = textscan( FileID, '%s%s' , 'Delimiter' , ',' );
fclose( FileID );

CurrentTotal = handles.CurrentTotal;

if Combo4 == 1
      handles.CurrentTotal = handles.CurrentTotal + str2num(Contents{1,2}{11,1} );
end
CurrentTotal = handles.CurrentTotal
set(handles.CurrentTotalEditBox, 'string' , handles.CurrentTotal)



% --- Executes on button press in Combo5PushButton.
function Combo5PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo5PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Combo5 = 1;
FileID = fopen('Price List.csv' , 'r' );
Contents = textscan( FileID, '%s%s' , 'Delimiter' , ',' );
fclose( FileID );

CurrentTotal = handles.CurrentTotal;


if Combo5 == 1
      handles.CurrentTotal = handles.CurrentTotal + str2num(Contents{1,2}{12,1} );
end
CurrentTotal = handles.CurrentTotal
set(handles.CurrentTotalEditBox, 'string' , handles.CurrentTotal)



% --- Executes on button press in Combo6PushButton.
function Combo6PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo6PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Combo6 = 1;
FileID = fopen('Price List.csv' , 'r' );
Contents = textscan( FileID, '%s%s' , 'Delimiter' , ',' );
fclose( FileID );

CurrentTotal = handles.CurrentTotal;


if Combo6 == 1
      handles.CurrentTotal = handles.CurrentTotal + str2num(Contents{1,2}{13,1} );
end
CurrentTotal = handles.CurrentTotal
set(handles.CurrentTotalEditBox, 'value' , handles.CurrentTotal)



% --- Executes on button press in AddToOrderPushButton.
function AddToOrderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to AddToOrderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%%% need to reset the toggle
Total = get(handles.CurrentTotalEditBox, 'value')
% Total = num2str(Total)
FileID = fopen('OrderHistory.csv' , 'a' );
fprintf(FileID ,'%d\n', Total );
% save('OrderHistory.csv');  %%% this line is only for .mat files.
fclose(FileID);
set(handles.CurrentTotalEditBox, 'value' , 0)

function ComboAll_Callback(hObject, eventdata, handles)
% need to check to see what push buttons were toggled.
%%% need to write each order to an active order file.



function CurrentTotalEditBox_Callback(hObject, eventdata, handles)
% hObject    handle to CurrentTotalEditBox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of CurrentTotalEditBox as text
%        str2double(get(hObject,'String')) returns contents of CurrentTotalEditBox as a double


% --- Executes during object creation, after setting all properties.
function CurrentTotalEditBox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to CurrentTotalEditBox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
