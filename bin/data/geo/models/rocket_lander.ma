//Maya ASCII 2019 scene
//Name: rocket_lander.ma
//Last modified: Sat, May 11, 2019 12:15:11 PM
//Codeset: 1252
requires maya "2019";
requires "mtoa" "3.1.2";
requires "mtoa" "3.1.2";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2019";
fileInfo "version" "2019";
fileInfo "cutIdentifier" "201812112215-434d8d9c04";
fileInfo "osv" "Microsoft Windows 10 Technical Preview  (Build 17763)\n";
fileInfo "license" "student";
createNode transform -s -n "persp";
	rename -uid "5E140F87-1C4F-6E2B-FDF7-3783E8CDF5CD";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -54.915346436671989 -30.130424506000509 -132.26280468410926 ;
	setAttr ".r" -type "double3" 20.061647273615254 923.79999999910774 0 ;
	setAttr ".rp" -type "double3" 2.5625480038978684e-15 1.9618491039371956e-17 -7.1054273576010019e-15 ;
	setAttr ".rpt" -type "double3" -5.6357509140369676e-14 1.3973647858211643e-14 2.2257103402222981e-14 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "0AB2DA50-6047-08D9-5D73-DA859FF03021";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999986;
	setAttr ".coi" 167.92345920092902;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "6B9C8AE5-C64D-CBAE-F520-73BCCC5561BE";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 1000.1 0 ;
	setAttr ".r" -type "double3" -89.999999999999986 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "BDD79324-5D4C-DAEA-BD95-ECA0A37A0295";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "76E423F1-EE4E-D426-158F-2BB349B3B8F5";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 1000.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "DACBEAE0-0B4E-659E-F98A-6D9758D0414A";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "side";
	rename -uid "0BFAA6E0-1244-72F8-45B9-AFB30D53A843";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 1000.1 0 0 ;
	setAttr ".r" -type "double3" 0 89.999999999999986 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "CA024088-3F4A-8F1C-CB46-48A714ED28D4";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "pCylinder1";
	rename -uid "CED02F84-4549-286C-9634-86BC4EE2A06B";
	setAttr ".s" -type "double3" 7.2312840195402615 30.291378068172868 7.2312840195402615 ;
createNode transform -n "transform2" -p "pCylinder1";
	rename -uid "C039201F-46BD-612D-F619-A6940C960D0E";
	setAttr ".v" no;
createNode mesh -n "pCylinderShape1" -p "transform2";
	rename -uid "1E936963-AA4E-22A0-F752-89A6E958854A";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.28374746814370155 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCone1";
	rename -uid "7888D338-1942-7CFF-2009-99874D3A0D07";
	setAttr ".t" -type "double3" 0 37.649365878377594 0 ;
	setAttr ".s" -type "double3" 7.2899100593747512 7.2899100593747512 7.2899100593747512 ;
createNode transform -n "transform1" -p "pCone1";
	rename -uid "3745EBA1-4C6B-B775-69BE-68A0E2C76234";
	setAttr ".v" no;
createNode mesh -n "pConeShape1" -p "transform1";
	rename -uid "CA98369A-DC42-3155-628E-5FA42CDE82FD";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCylinder2";
	rename -uid "340F17B3-4BA3-AAC3-A0FF-BDBCF86F2838";
	setAttr ".rp" -type "double3" -0.14553930086934841 7.3239326852282716 -0.50199473032987108 ;
	setAttr ".sp" -type "double3" -0.14553930086934841 7.3239326852282716 -0.50199473032987108 ;
createNode mesh -n "pCylinder2Shape" -p "pCylinder2";
	rename -uid "B6FE5868-4FC1-B737-83F3-51A20853CC57";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode lightLinker -s -n "lightLinker1";
	rename -uid "34A1EB09-4AE1-4F9B-315C-7FBA2C8C1B2A";
	setAttr -s 2 ".lnk";
	setAttr -s 2 ".slnk";
createNode displayLayerManager -n "layerManager";
	rename -uid "0F035A63-43BE-5C70-D568-52BDAC5AD937";
createNode displayLayer -n "defaultLayer";
	rename -uid "10E832E4-4A4A-700D-B250-AA9F05255DDD";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "C1FFA22A-41EC-CB5F-C7FC-D6B19854A3E6";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "79A54037-D548-6BF0-91B0-2FBA68BFDBE1";
	setAttr ".g" yes;
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "D46280B1-48C9-C277-9F4B-B1B8FDD5191C";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "CAB2AD05-4262-52FD-097D-33B9396E4B20";
createNode polyCylinder -n "polyCylinder1";
	rename -uid "30C93746-8E4D-E82D-B11E-2BA27DFC775A";
	setAttr ".sc" 1;
	setAttr ".cuv" 3;
createNode polyCone -n "polyCone1";
	rename -uid "F83CCC31-0A47-E5C1-B2F1-559FB5E15BE3";
	setAttr ".cuv" 3;
createNode polySubdFace -n "polySubdFace1";
	rename -uid "F501C8A1-E84E-7E41-D23A-8D903015964D";
	setAttr ".ics" -type "componentList" 1 "f[*]";
	setAttr ".dv" 2;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "ECDA6B47-F149-4E77-50A4-2DB9C518B80D";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $nodeEditorPanelVisible = stringArrayContains(\"nodeEditorPanel1\", `getPanel -vis`);\n\tint    $nodeEditorWorkspaceControlOpen = (`workspaceControl -exists nodeEditorPanel1Window` && `workspaceControl -q -visible nodeEditorPanel1Window`);\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\n\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n"
		+ "            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n"
		+ "            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n"
		+ "            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n"
		+ "            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n"
		+ "            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n"
		+ "            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n"
		+ "            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n"
		+ "            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n"
		+ "            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n"
		+ "            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n"
		+ "            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1559\n            -height 702\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n"
		+ "            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -isSet 0\n            -isSetMember 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            -renderFilterIndex 0\n            -selectionOrder \"chronological\" \n            -expandAttribute 0\n            $editorName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n"
		+ "            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n"
		+ "            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n"
		+ "                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 1\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n"
		+ "                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 1\n                -autoFitTime 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n"
		+ "                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -showCurveNames 0\n                -showActiveCurveNames 0\n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                -valueLinesToggle 1\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n"
		+ "            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 1\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n"
		+ "                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n"
		+ "                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -autoFitTime 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"timeEditorPanel\" (localizedPanelLabel(\"Time Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Time Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -autoFitTime 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -autoFitTime 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showConstraintLabels 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n"
		+ "                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"nodeEditorPanel\" (localizedPanelLabel(\"Node Editor\")) `;\n\tif ($nodeEditorPanelVisible || $nodeEditorWorkspaceControlOpen) {\n"
		+ "\t\tif (\"\" == $panelName) {\n\t\t\tif ($useSceneConfig) {\n\t\t\t\t$panelName = `scriptedPanel -unParent  -type \"nodeEditorPanel\" -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n"
		+ "                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\t}\n\t\t} else {\n\t\t\t$label = `panel -q -label $panelName`;\n\t\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n"
		+ "                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\tif (!$useSceneConfig) {\n\t\t\t\tpanel -e -l $label $panelName;\n\t\t\t}\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"shapePanel\" (localizedPanelLabel(\"Shape Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tshapePanel -edit -l (localizedPanelLabel(\"Shape Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"posePanel\" (localizedPanelLabel(\"Pose Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tposePanel -edit -l (localizedPanelLabel(\"Pose Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"profilerPanel\" (localizedPanelLabel(\"Profiler Tool\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Profiler Tool\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"contentBrowserPanel\" (localizedPanelLabel(\"Content Browser\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Content Browser\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1559\\n    -height 702\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1559\\n    -height 702\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "F9D429E0-044B-B7D9-0584-71A7BCE917A5";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode polyExtrudeFace -n "polyExtrudeFace1";
	rename -uid "86D842A1-42F5-63DC-542A-07B05F9953FA";
	setAttr ".ics" -type "componentList" 52 "f[6:7]" "f[72]" "f[75]" "f[78]" "f[81]" "f[121]" "f[123]" "f[125]" "f[127]" "f[129]" "f[131]" "f[133]" "f[135]" "f[137]" "f[139]" "f[141]" "f[143]" "f[145]" "f[147]" "f[149]" "f[151]" "f[153]" "f[155]" "f[157]" "f[159]" "f[215:216]" "f[218:223]" "f[416]" "f[425:427]" "f[434:436]" "f[443]" "f[445]" "f[563:565]" "f[569:571]" "f[575:577]" "f[581:583]" "f[587:589]" "f[593:595]" "f[599:601]" "f[605:607]" "f[611:613]" "f[617:619]" "f[623:625]" "f[629:631]" "f[635:637]" "f[641:643]" "f[647:649]" "f[653:655]" "f[659:661]" "f[665:667]" "f[671:673]" "f[677:679]";
	setAttr ".ix" -type "matrix" 7.2312840195402615 0 0 0 0 30.291378068172868 0 0 0 0 7.2312840195402615 0
		 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" -1.4365349 -15.145691 -1.5250167 ;
	setAttr ".rs" 57859;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -6.8773616835430902 -30.291381679186529 -7.0543252221413102 ;
	setAttr ".cbx" -type "double3" 4.0042919063314848 -1.0155975915996575e-06 4.0042919063314848 ;
createNode polyTweak -n "polyTweak1";
	rename -uid "0CB47114-4B1A-C33F-58EB-33B663118C17";
	setAttr ".uopa" yes;
	setAttr -s 802 ".tk";
	setAttr ".tk[0:165]" -type "float3"  0 -1.6763806e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 4.1723251e-07 0 -2.9802322e-08 -1.64004469
		 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 -1.59341574
		 -1.0728836e-06 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 1.1920929e-06
		 0 -1.6763806e-07 1.6093254e-06 0 4.3213367e-07 1.50120533 0 -1.6763806e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.7136335e-07 0 1.55316305 -1.0691583e-06 0 0 -1.6018748e-07
		 0 0 -1.5646219e-07 0 0 -1.5646219e-07 0 0 -1.6018748e-07 4.1723251e-07 0 -1.6763806e-07
		 4.1723251e-07 0 -1.6018748e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6018748e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 1.1920929e-06
		 0 -1.6763806e-07 1.6093254e-06 0 -1.6018748e-07 4.1723251e-07 0 -1.527369e-07 0 0
		 -1.527369e-07 0 0 -1.527369e-07 0 0 -1.527369e-07 0 0 -1.527369e-07 0 0 -1.6391277e-07
		 0 0 -1.6763806e-07 0 0 -4.5448542e-07 0 0 -1.6763806e-07 0 0 -1.0430813e-07 0 0 -1.5646219e-07
		 0 0 -3.7252903e-08 0 0 -9.6857548e-08 0 0 -1.6763806e-07 4.1723251e-07 0 -2.0116568e-07
		 4.1723251e-07 0 -1.6018748e-07 4.1723251e-07 0 -7.3760748e-07 4.1723251e-07 0 -1.6763806e-07
		 0 0 -1.3783574e-07 0 0 -1.5646219e-07 0 0 -1.4156103e-07 0 0 -1.6763806e-07 0 0 6.6310167e-07
		 0 0 -1.6018748e-07 0 0 -1.3783574e-07 0 0 -1.6391277e-07 0 0 -7.3388219e-07 0 0 -1.6763806e-07
		 0 0 -1.9744039e-07 0 0 -1.6391277e-07 0 0 -1.0803342e-07 0 0 -1.6018748e-07 0 0 -1.0803342e-07
		 0 0 -1.6391277e-07 4.1723251e-07 0 -4.5076013e-07 4.1723251e-07 0 -1.6018748e-07
		 4.1723251e-07 0 -3.3527613e-08 4.1723251e-07 0 -1.6391277e-07 0 0 1.15484e-07 0 0
		 -1.6018748e-07 0 0 1.1175871e-07 0 0 -1.6391277e-07 0 0 -6.1839819e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6018748e-07 0 0 -1.7136335e-07
		 0 0 -1.6763806e-07 0 0 -1.6018748e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 2.3841858e-07
		 -1.6763806e-07 -3.5762787e-07 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.7136335e-07
		 0 0 -1.6763806e-07 0 0 -1.7508864e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 -1.1920929e-07 -1.6018748e-07 -0.0056991708 0 -1.6018748e-07 0 0 -1.5646219e-07
		 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.527369e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6391277e-07 0 0 -1.527369e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07
		 0 0 -1.527369e-07 0 0 -1.6391277e-07 0 0 -1.7136335e-07 0 0 -1.5646219e-07 0 0 -1.527369e-07
		 0 0 -6.0349703e-07 0 0 -1.7136335e-07 0 0 1.1920929e-07 0 0 -1.6391277e-07 0 0 1.1175871e-07
		 0 0 -1.7136335e-07 0 0 -1.6018748e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.7136335e-07 0 0 -1.6763806e-07 0 0 -1.7136335e-07
		 0 0 -1.6763806e-07 0;
	setAttr ".tk[166:331]" 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07
		 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07
		 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.0430813e-07 0 0 -1.0058284e-07
		 0 0 -1.6763806e-07 0 0 -1.0430813e-07 0 0 -3.7252903e-08 0 0 -7.1898103e-07 0 0 -1.8253922e-07
		 0 0 -1.6763806e-07 0 0 -7.2643161e-07 0 0 -9.6857548e-08 0 0 -1.3038516e-07 0 0 -1.3038516e-07
		 0 0 -1.6763806e-07 0 0 -1.3038516e-07 0 0 -7.3760748e-07 0 0 6.7055225e-07 0 0 6.7427754e-07
		 0 0 -1.6763806e-07 0 0 4.2840838e-07 0 0 -1.3783574e-07 0 0 -5.6996942e-07 -1.64004517
		 0 -5.7369471e-07 -1.64004517 0 -2.6077032e-08 -1.64004517 0 4.3213367e-07 0 0 -1.4156103e-07
		 0 0 -1.0728836e-06 0 0 -1.0728836e-06 0 0 -1.6391277e-07 0 0 4.3213367e-07 0 0 -7.3388219e-07
		 0 0 4.3213367e-07 0 0 4.3213367e-07 0 0 -1.6391277e-07 0 0 4.3213367e-07 0 0 -1.0803342e-07
		 0 0 6.7055225e-07 0 0 6.7055225e-07 0 0 -1.6391277e-07 0 0 -1.3411045e-07 0 0 -3.3527613e-08
		 0 0 -7.301569e-07 0 0 -1.3411045e-07 0 0 -1.6391277e-07 0 0 -7.301569e-07 0 0 1.15484e-07
		 0 -1.59341574 -4.0978193e-07 0 -1.59341574 1.1175871e-07 0 -1.59341574 -1.0728836e-06
		 0 0 -1.0430813e-07 0 0 -1.7136335e-07 0 0 -4.4703484e-07 0 0 -1.0430813e-07 0 0 -1.6763806e-07
		 0 0 -4.4703484e-07 0 0 -1.7136335e-07 0 2.3841858e-07 -2.9802322e-08 -3.5762787e-07
		 0 -2.9802322e-08 0 2.3841858e-07 -1.6763806e-07 -3.5762787e-07 2.3841858e-07 1.2665987e-07
		 -3.5762787e-07 0 -1.6018748e-07 0 0 -6.146729e-07 0 0 1.2665987e-07 0 0 -1.6763806e-07
		 0 0 -6.146729e-07 0 0 -1.7136335e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.7508864e-07 0 -1.1920929e-07 -1.937151e-07 1.49550605 -1.1920929e-07
		 -1.937151e-07 1.49550605 0 4.3213367e-07 1.50120497 0 -1.6018748e-07 0 -1.1920929e-07
		 -1.6018748e-07 -0.0056991708 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07 0 0 -1.6763806e-07
		 0 0 -1.6018748e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.7136335e-07
		 0 0 -6.1094761e-07 0 0 -1.6391277e-07 0 0 1.2293458e-07 0 0 1.1920929e-07 0 0 -1.7136335e-07
		 0 0 1.2293458e-07 0 0 -1.5646219e-07 0 1.55316305 -2.4959445e-07 0 1.55316305 -2.4959445e-07
		 0 1.55316305 -1.0691583e-06 0 0 -4.4330955e-07 0 0 1.1920929e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0;
	setAttr ".tk[332:497]" 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.7136335e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.7136335e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.7136335e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.5646219e-07
		 0 0 -1.6763806e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.5646219e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.5646219e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.527369e-07 0 0 -1.527369e-07 0 0 -1.6018748e-07
		 0 0 -1.6018748e-07 0 0 -1.6391277e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07 0 0 -1.6763806e-07
		 0 0 -1.6018748e-07 0 0 -1.7136335e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07
		 0 0 -1.527369e-07 0 0 -1.7136335e-07 0 0 -1.527369e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07
		 0 0 -1.527369e-07 0 0 -1.7136335e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07
		 0 0 -1.6018748e-07 0 0 -1.7136335e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07 0 0 -1.6763806e-07
		 0 0 -1.6018748e-07 0 0 -1.7136335e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07
		 0 0 -1.527369e-07 0 0 -1.6391277e-07 0 0 -1.527369e-07 0 0 -1.527369e-07 0 0 -1.6391277e-07
		 0 0 -1.5646219e-07 0 0 -1.6391277e-07 0 0 -1.5646219e-07 0 0 -1.5646219e-07 0 0 -1.6763806e-07
		 0 0 -1.6018748e-07 0 0 -1.6763806e-07 0 0 -1.5646219e-07 0 0 -1.6018748e-07 0 0 -1.6391277e-07
		 0 0 -1.5646219e-07 0 0 -1.7136335e-07 0 0 -1.5646219e-07 0 0 -1.5646219e-07 0 0 -1.6763806e-07
		 0 0 -1.5646219e-07 0 0 -1.6763806e-07 0 0 -1.6018748e-07 0 0 -1.6018748e-07 0 0 -1.527369e-07
		 0 0 -1.7136335e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.7136335e-07 0 0 -1.527369e-07
		 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.527369e-07
		 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.527369e-07
		 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.6391277e-07
		 0 0 -1.7136335e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0;
	setAttr ".tk[498:663]" 0 -1.6763806e-07 0 0 -1.527369e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.8253922e-07 0 0 -4.4703484e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.5646219e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -7.2643161e-07
		 0 0 -1.8626451e-07 0 0 -6.1094761e-07 0 0 1.1920929e-07 0 0 -1.6018748e-07 0 0 -6.1094761e-07
		 0 0 -1.6391277e-07 0 0 6.7427754e-07 0 0 -7.3388219e-07 0 0 -2.9802322e-08 0 0 -2.9802322e-08
		 0 0 -1.527369e-07 0 0 1.1920929e-07 0 0 1.1920929e-07 0 0 4.2840838e-07 0 0 6.6310167e-07
		 0 0 -4.4703484e-07 0 0 -1.0430813e-07 0 0 -1.6763806e-07 0 0 -4.4703484e-07 0 0 -2.9802322e-08
		 0 0 -1.0728836e-06 0 0 -7.3388219e-07 0 0 -1.937151e-07 0 0 -1.8998981e-07 0 0 -1.6763806e-07
		 0 0 -1.0430813e-07 0 0 -1.0430813e-07 0 0 4.3213367e-07 0 0 -1.9744039e-07 0 0 -1.0058284e-07
		 0 0 -1.0058284e-07 0 0 -1.6018748e-07 0 0 -1.0058284e-07 0 0 -1.8998981e-07 0 0 6.7055225e-07
		 0 0 -4.5076013e-07 0 0 -2.6077032e-08 0 0 -2.6077032e-08 0 0 -1.6018748e-07 0 0 -4.4330955e-07
		 0 0 -4.4330955e-07 0 0 -1.3411045e-07 0 0 -3.3527613e-08 0 0 1.2293458e-07 0 0 1.1920929e-07
		 0 0 -1.6018748e-07 0 0 1.2293458e-07 0 0 -2.6077032e-08 0 0 -7.301569e-07 0 0 -6.1839819e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -6.1094761e-07 0 0 -6.1094761e-07
		 0 0 -1.0430813e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6018748e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -2.9802322e-08 0 0 -1.7136335e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 1.2665987e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.7508864e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07
		 0 0 -1.6763806e-07 0 0 -1.5646219e-07 -7.4505806e-09 0 -1.6018748e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.5646219e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.527369e-07 0 0 -1.5646219e-07 0 0 -1.5646219e-07 -7.4505806e-09 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.527369e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.527369e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -6.1094761e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.527369e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -2.6077032e-08 0 0 -6.1094761e-07 0 0 -1.5646219e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07
		 0 0 -1.5646219e-07 0 0 -1.5646219e-07 0 0 -4.4330955e-07 0 0 -3.7252903e-08 0 0 -1.6763806e-07
		 0 0 -1.6018748e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0;
	setAttr ".tk[664:801]" 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07
		 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.527369e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6018748e-07 0 0 -1.7136335e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6018748e-07 0 0 -1.7136335e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.527369e-07 0 0 -1.7136335e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.527369e-07 0 0 -1.7136335e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6018748e-07
		 0 0 -1.7136335e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.6018748e-07 0 0 -1.7136335e-07
		 0 0 -1.6391277e-07 0 0 -1.6391277e-07 0 0 -1.527369e-07 0 0 -1.6391277e-07 0 0 -1.6391277e-07
		 0 0 -1.6391277e-07 0 0 -1.5646219e-07 0 0 -1.6763806e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07
		 0 0 -1.6018748e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.5646219e-07
		 0 0 -1.7136335e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.5646219e-07 0 0 -1.6763806e-07
		 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.6763806e-07 0 0 -1.7136335e-07
		 0 0 -1.7136335e-07 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07
		 0 0 -1.6391277e-07 0 0 -1.6763806e-07 0 0 -1.6763806e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07
		 0 0 -1.6763806e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.6763806e-07
		 0 0 -1.7136335e-07 0 0 -1.7136335e-07 0 0 -1.6763806e-07 0 0 -1.7136335e-07 0 0 -1.7136335e-07
		 0;
createNode polyExtrudeFace -n "polyExtrudeFace2";
	rename -uid "D252F50E-4CE4-8A73-8C88-0B92CBFB5A40";
	setAttr ".ics" -type "componentList" 98 "f[0:3]" "f[7]" "f[18:19]" "f[40:59]" "f[61:62]" "f[64:65]" "f[67:68]" "f[70:71]" "f[73:74]" "f[76:77]" "f[79:80]" "f[82:83]" "f[86]" "f[89]" "f[95]" "f[97:98]" "f[100:101]" "f[104]" "f[107]" "f[109:110]" "f[112:113]" "f[115:116]" "f[118:119]" "f[121]" "f[123]" "f[125]" "f[127]" "f[129]" "f[131]" "f[133]" "f[135]" "f[137]" "f[139]" "f[141]" "f[143]" "f[145]" "f[147]" "f[149]" "f[151]" "f[153]" "f[155]" "f[157]" "f[159:199]" "f[202]" "f[205]" "f[208]" "f[211]" "f[223]" "f[256]" "f[259]" "f[320:379]" "f[381:388]" "f[390:397]" "f[399:406]" "f[409:415]" "f[419:424]" "f[428:433]" "f[437:442]" "f[445:451]" "f[455:456]" "f[458:460]" "f[467]" "f[482:483]" "f[491:494]" "f[496]" "f[500:505]" "f[509:510]" "f[512]" "f[518:519]" "f[521]" "f[527:530]" "f[534]" "f[536:541]" "f[543:550]" "f[552:559]" "f[563:565]" "f[569:571]" "f[575:577]" "f[581:583]" "f[587:589]" "f[593:595]" "f[599:601]" "f[605:607]" "f[611:613]" "f[617:619]" "f[623:625]" "f[629:631]" "f[635:637]" "f[641:643]" "f[647:649]" "f[653:655]" "f[659:661]" "f[665:667]" "f[671:673]" "f[677:799]" "f[801]" "f[817]" "f[830]";
	setAttr ".ix" -type "matrix" 7.2312840195402615 0 0 0 0 30.291378068172868 0 0 0 0 7.2312840195402615 0
		 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 5.6156807 -3.6110137e-06 0 ;
	setAttr ".rs" 36361;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -7.2312857436127222 -30.291381679186529 -7.2312874676851839 ;
	setAttr ".cbx" -type "double3" 18.46264717435351 30.291374457159208 7.2312874676851839 ;
createNode polyExtrudeFace -n "polyExtrudeFace3";
	rename -uid "FECD5B30-42B1-4F92-9103-948F7F0DA2DC";
	setAttr ".ics" -type "componentList" 40 "f[121]" "f[123]" "f[125]" "f[127]" "f[129]" "f[131]" "f[133]" "f[135]" "f[137]" "f[139]" "f[141]" "f[143]" "f[145]" "f[147]" "f[149]" "f[151]" "f[153]" "f[155]" "f[157]" "f[159]" "f[563:565]" "f[569:571]" "f[575:577]" "f[581:583]" "f[587:589]" "f[593:595]" "f[599:601]" "f[605:607]" "f[611:613]" "f[617:619]" "f[623:625]" "f[629:631]" "f[635:637]" "f[641:643]" "f[647:649]" "f[653:655]" "f[659:661]" "f[665:667]" "f[671:673]" "f[677:679]";
	setAttr ".ix" -type "matrix" 7.2312840195402615 0 0 0 0 30.291378068172868 0 0 0 0 7.2312840195402615 0
		 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 2.1550906e-07 -30.291382 -4.3101812e-07 ;
	setAttr ".rs" 41280;
	setAttr ".lt" -type "double3" 0 0 -1.4132312039334174 ;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -4.0042914753133694 -30.291381679186529 -4.0042927683677156 ;
	setAttr ".cbx" -type "double3" 4.0042919063314848 -30.291381679186529 4.0042919063314848 ;
createNode polyExtrudeFace -n "polyExtrudeFace4";
	rename -uid "4E15FF1C-4362-3CF6-DF7C-2D879C7489C7";
	setAttr ".ics" -type "componentList" 20 "f[563]" "f[569]" "f[575]" "f[581]" "f[587]" "f[593]" "f[599]" "f[605]" "f[611]" "f[617]" "f[623]" "f[629]" "f[635]" "f[641]" "f[647]" "f[653]" "f[659]" "f[665]" "f[671]" "f[677]";
	setAttr ".ix" -type "matrix" 7.2312840195402615 0 0 0 0 30.291378068172868 0 0 0 0 7.2312840195402615 0
		 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 2.1550906e-07 -28.878153 -1.1852998e-06 ;
	setAttr ".rs" 43885;
	setAttr ".lt" -type "double3" 0 -5.2899960413109633e-17 -1.1121257091018921 ;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" -2.1051937641608256 -28.878151902003282 -2.1051963502695172 ;
	setAttr ".cbx" -type "double3" 2.105194195178941 -28.878151902003282 2.1051939796698833 ;
createNode polyUnite -n "polyUnite1";
	rename -uid "5732B821-4F87-9921-A60C-A38C74FF8070";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId1";
	rename -uid "9B24AED5-456F-E6EF-7E4B-E0AB5F76DDA3";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts1";
	rename -uid "D5BE8C32-4290-E1C4-D71E-4B9F711F8628";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:1203]";
createNode groupId -n "groupId2";
	rename -uid "2B4D5BD8-4C55-B2A0-C660-DAAE5B5A6AEC";
	setAttr ".ihi" 0;
createNode groupId -n "groupId3";
	rename -uid "38CFEB0F-4F4F-9216-6EFC-4F874F7C39F4";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts2";
	rename -uid "455C842E-4886-A1EE-5686-86B207CEDDED";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:20]";
createNode groupId -n "groupId4";
	rename -uid "51635C21-4F71-9E91-465D-7D8C42CB58DA";
	setAttr ".ihi" 0;
createNode groupId -n "groupId5";
	rename -uid "49830C81-469D-BF4C-4250-D0B0E060AECA";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts3";
	rename -uid "54997812-4055-D180-8212-6BBEB95C949C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:1224]";
select -ne :time1;
	setAttr ".o" 1;
	setAttr ".unw" 1;
select -ne :hardwareRenderingGlobals;
	setAttr ".otfna" -type "stringArray" 22 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surface" "Particles" "Particle Instance" "Fluids" "Strokes" "Image Planes" "UI" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Hair Systems" "Follicles" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 22 0 1 1 1 1 1
		 1 1 1 0 0 0 0 0 0 0 0 0
		 0 0 0 0 ;
	setAttr ".fprt" yes;
select -ne :renderPartition;
	setAttr -s 2 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 4 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderingList1;
select -ne :initialShadingGroup;
	setAttr -s 5 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 5 ".gn";
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultRenderGlobals;
	setAttr ".ren" -type "string" "arnold";
select -ne :defaultResolution;
	setAttr ".pa" 1;
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :ikSystem;
	setAttr -s 4 ".sol";
connectAttr "groupParts1.og" "pCylinderShape1.i";
connectAttr "groupId1.id" "pCylinderShape1.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "pCylinderShape1.iog.og[0].gco";
connectAttr "groupId2.id" "pCylinderShape1.ciog.cog[0].cgid";
connectAttr "groupParts2.og" "pConeShape1.i";
connectAttr "groupId3.id" "pConeShape1.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "pConeShape1.iog.og[0].gco";
connectAttr "groupId4.id" "pConeShape1.ciog.cog[0].cgid";
connectAttr "groupParts3.og" "pCylinder2Shape.i";
connectAttr "groupId5.id" "pCylinder2Shape.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "pCylinder2Shape.iog.og[0].gco";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "polyCylinder1.out" "polySubdFace1.ip";
connectAttr "polyTweak1.out" "polyExtrudeFace1.ip";
connectAttr "pCylinderShape1.wm" "polyExtrudeFace1.mp";
connectAttr "polySubdFace1.out" "polyTweak1.ip";
connectAttr "polyExtrudeFace1.out" "polyExtrudeFace2.ip";
connectAttr "pCylinderShape1.wm" "polyExtrudeFace2.mp";
connectAttr "polyExtrudeFace2.out" "polyExtrudeFace3.ip";
connectAttr "pCylinderShape1.wm" "polyExtrudeFace3.mp";
connectAttr "polyExtrudeFace3.out" "polyExtrudeFace4.ip";
connectAttr "pCylinderShape1.wm" "polyExtrudeFace4.mp";
connectAttr "pCylinderShape1.o" "polyUnite1.ip[0]";
connectAttr "pConeShape1.o" "polyUnite1.ip[1]";
connectAttr "pCylinderShape1.wm" "polyUnite1.im[0]";
connectAttr "pConeShape1.wm" "polyUnite1.im[1]";
connectAttr "polyExtrudeFace4.out" "groupParts1.ig";
connectAttr "groupId1.id" "groupParts1.gi";
connectAttr "polyCone1.out" "groupParts2.ig";
connectAttr "groupId3.id" "groupParts2.gi";
connectAttr "polyUnite1.out" "groupParts3.ig";
connectAttr "groupId5.id" "groupParts3.gi";
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "pCylinderShape1.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape1.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pConeShape1.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pConeShape1.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinder2Shape.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "groupId1.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId2.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId3.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId4.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId5.msg" ":initialShadingGroup.gn" -na;
// End of rocket_lander.ma
