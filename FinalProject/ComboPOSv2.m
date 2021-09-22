function varargout = ComboPOSv2(varargin)
% COMBOPOSV2 MATLAB code for ComboPOSv2.fig
%      COMBOPOSV2, by itself, creates a new COMBOPOSV2 or raises the existing
%      singleton*.
%
%      H = COMBOPOSV2 returns the handle to a new COMBOPOSV2 or the handle to
%      the existing singleton*.
%
%      COMBOPOSV2('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in COMBOPOSV2.M with the given input arguments.
%
%      COMBOPOSV2('Property','Value',...) creates a new COMBOPOSV2 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ComboPOSv2_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ComboPOSv2_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ComboPOSv2

% Last Modified by GUIDE v2.5 28-Apr-2018 14:41:52

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ComboPOSv2_OpeningFcn, ...
                   'gui_OutputFcn',  @ComboPOSv2_OutputFcn, ...
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


% --- Executes just before ComboPOSv2 is made visible.
function ComboPOSv2_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ComboPOSv2 (see VARARGIN)

% Choose default command line output for ComboPOSv2
handles.output = hObject;

FileID = fopen('Price List.csv','r');
Contents = textscan( FileID, '%s%s','Delimiter',',');
fclose(FileID);

for Index = 1 : 1 : size(Contents{1},1)
    Options{Index,1} = Contents{1}{Index};
    Options{Index,2} = Contents{2}{Index};
end;

handles.Options = Options;



% Update handles structure
guidata(hObject, handles);

% UIWAIT makes ComboPOSv2 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = ComboPOSv2_OutputFcn(hObject, eventdata, handles) 
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
close(ComboPOSv2)

% --- Executes on button press in TenderPushButton.
function TenderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to TenderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
TenderPOS
close(ComboPOSv2)

% --- Executes on button press in Combo1PushButton.
function Combo1PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo1PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Options = handles.Options;
Price = str2num(Options{8, 2});
set(handles.CurrentTotalEditBox, 'string' , Price );



% --- Executes on button press in Combo2PushButton.
function Combo2PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo2PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Options = handles.Options;
Price = str2num(Options{9, 2});
set(handles.CurrentTotalEditBox, 'string' , Price );

% --- Executes on button press in Combo3PushButton.
function Combo3PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo3PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Options = handles.Options;
Price = str2num(Options{10, 2});
set(handles.CurrentTotalEditBox, 'string' , Price );

% --- Executes on button press in Combo4PushButton.
function Combo4PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo4PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Options = handles.Options;
Price = str2num(Options{11, 2});
set(handles.CurrentTotalEditBox, 'string' , Price );

% --- Executes on button press in Combo5PushButton.
function Combo5PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo5PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Options = handles.Options;
Price = str2num(Options{12, 2});
set(handles.CurrentTotalEditBox, 'string' , Price );

% --- Executes on button press in Combo6PushButton.
function Combo6PushButton_Callback(hObject, eventdata, handles)
% hObject    handle to Combo6PushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Options = handles.Options;
Price = str2num(Options{13, 2});
set(handles.CurrentTotalEditBox, 'string' , Price );

% --- Executes on button press in AddToOrderPushButton.
function AddToOrderPushButton_Callback(hObject, eventdata, handles)
% hObject    handle to AddToOrderPushButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
PriceAsString = get(handles.CurrentTotalEditBox, 'string' );
PriceAsNum = str2num(PriceAsString);

FileID = fopen('GrossIncome.csv' , 'a');
fprintf(FileID, '%.2f\n' , PriceAsNum );
fclose(FileID);

FileID = fopen('CurrentOrder.csv' , 'w');
fprintf(FileID, '%.2f' , PriceAsNum);
fclose(FileID);




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
