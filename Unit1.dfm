object FDATECEC: TFDATECEC
  Left = 0
  Top = 0
  Caption = 'FDATECEC'
  ClientHeight = 544
  ClientWidth = 1092
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1092
    Height = 67
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 867
    object Label1: TLabel
      Left = 136
      Top = 17
      Width = 62
      Height = 15
      Caption = 'DE LA DATA'
    end
    object Label2: TLabel
      Left = 239
      Top = 17
      Width = 79
      Height = 15
      Caption = 'PANA LA DATA'
    end
    object Label3: TLabel
      Left = 342
      Top = 17
      Width = 57
      Height = 15
      Caption = 'OPERATOR'
    end
    object SpeedButton1: TSpeedButton
      Left = 544
      Top = 15
      Width = 113
      Height = 46
      Caption = 'Cauta'
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 663
      Top = 15
      Width = 113
      Height = 46
      Caption = 'Anuleaza'
    end
    object DateTimePicker1: TDateTimePicker
      Left = 136
      Top = 38
      Width = 97
      Height = 23
      Date = 45272.000000000000000000
      Time = 0.849744456019834600
      TabOrder = 0
    end
    object DateTimePicker2: TDateTimePicker
      Left = 239
      Top = 38
      Width = 97
      Height = 23
      Date = 45272.000000000000000000
      Time = 0.849817847221856900
      TabOrder = 1
    end
    object ComboBoxEx1: TComboBoxEx
      Left = 342
      Top = 38
      Width = 145
      Height = 24
      ItemsEx = <>
      TabOrder = 2
      Text = 'ComboBoxEx1'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 483
    Width = 1092
    Height = 61
    Align = alBottom
    TabOrder = 1
    ExplicitTop = 471
    ExplicitWidth = 867
  end
  object Panel3: TPanel
    Left = 0
    Top = 67
    Width = 1092
    Height = 416
    Align = alClient
    TabOrder = 2
    ExplicitWidth = 867
    ExplicitHeight = 404
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 1090
      Height = 414
      ActivePage = TabSheet1
      Align = alClient
      TabOrder = 0
      ExplicitWidth = 865
      ExplicitHeight = 402
      object TabSheet1: TTabSheet
        Caption = 'LISTA CECURILOR'
        object DBGrid1: TDBGrid
          Left = 0
          Top = 0
          Width = 1082
          Height = 384
          Align = alClient
          DataSource = DM.DSDateCec
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -12
          TitleFont.Name = 'Segoe UI'
          TitleFont.Style = []
          OnDblClick = DBGrid1DblClick
          Columns = <
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'NR_CEC'
              Title.Alignment = taCenter
              Title.Caption = 'Nr_Cec'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 99
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'DATA_CEC'
              Title.Alignment = taCenter
              Title.Caption = 'Data_Cec'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 249
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'NR_POZ'
              Title.Alignment = taCenter
              Title.Caption = 'Nr_poz'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 73
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'SUMA'
              Title.Alignment = taCenter
              Title.Caption = 'Suma'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 76
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'VALOAREA'
              Title.Alignment = taCenter
              Title.Caption = 'Discount(%)'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 94
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'SUMA_DISC'
              Title.Alignment = taCenter
              Title.Caption = 'Suma Disc.'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 86
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'SUMA_CEC'
              Title.Alignment = taCenter
              Title.Caption = 'Suma_Cec'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 107
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'CLIENT'
              Title.Alignment = taCenter
              Title.Caption = 'Client'
              Width = 143
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'OPERATOR'
              Title.Alignment = taCenter
              Title.Caption = 'Operator'
              Width = 182
              Visible = True
            end>
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'DATE CEC'
        ImageIndex = 1
        object DBGrid2: TDBGrid
          Left = 0
          Top = 0
          Width = 1082
          Height = 384
          Align = alClient
          DataSource = DM.DSQVANZARE
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -12
          TitleFont.Name = 'Segoe UI'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              Title.Alignment = taCenter
              Title.Caption = 'Nr'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 40
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'COD_PRODUS'
              Title.Alignment = taCenter
              Title.Caption = 'Cod Produs'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 99
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'DENUMIRE'
              Title.Alignment = taCenter
              Title.Caption = 'Produs'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 249
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'CANTITATEA'
              Title.Alignment = taCenter
              Title.Caption = 'Cant.'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 46
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'PRET_VANZ'
              Title.Alignment = taCenter
              Title.Caption = 'Cost'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 74
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'SUMA'
              Title.Alignment = taCenter
              Title.Caption = 'Suma'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 76
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'PROCENT'
              Title.Alignment = taCenter
              Title.Caption = 'Discount'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 71
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'SUMA_DISC'
              Title.Alignment = taCenter
              Title.Caption = 'Suma Disc.'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 86
              Visible = True
            end
            item
              Alignment = taCenter
              Expanded = False
              FieldName = 'SUMA_TOTAL'
              Title.Alignment = taCenter
              Title.Caption = 'Suma total'
              Title.Font.Charset = DEFAULT_CHARSET
              Title.Font.Color = clWindowText
              Title.Font.Height = -13
              Title.Font.Name = 'Tahoma'
              Title.Font.Style = [fsBold]
              Width = 90
              Visible = True
            end>
        end
      end
    end
  end
end
